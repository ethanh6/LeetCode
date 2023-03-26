import os
import leetcode
import leetcode.auth
from dotenv import load_dotenv
from html2text import html2text

load_dotenv()


# sample question URL
# https://leetcode.com/problems/longest-common-subsequence/
# https://leetcode.com/problems/two-sum/description/
# get questioni slug form question url
question_slug = input("Question URL? ").split("/")[4]


# Get the leetcode_session token from browser, and put it into .env
leetcode_session = os.getenv("LEETCODE_SESSION")


# setup the api instance
configuration = leetcode.Configuration()
configuration.api_key["LEETCODE_SESSION"] = leetcode_session
csrf_token = leetcode.auth.get_csrf_cookie(leetcode_session)
configuration.api_key["x-csrftoken"] = csrf_token
configuration.api_key["csrftoken"] = csrf_token
configuration.api_key["Referer"] = "https://leetcode.com"
configuration.debug = False
api_instance = leetcode.DefaultApi(leetcode.ApiClient(configuration))


# graphql request object, this will be passed to the api
def get_request(slug):
    return leetcode.GraphqlQuery(
        query="""
        query getQuestionDetail($titleSlug: String!) {
          question(titleSlug: $titleSlug) {
            questionId
            questionFrontendId
            boundTopicId
            title
            content
            translatedTitle
            difficulty
            similarQuestions
            topicTags {
              name
              slug
              translatedName
              __typename
            }
            companyTagStats
            codeSnippets {
              lang
              langSlug
              code
              __typename
            }
            stats
            codeDefinition
            hints
            solution {
              id
              canSeeDetail
              __typename
            }
            status
            sampleTestCase
            translatedContent
          }
        }
    """,
        variables=leetcode.GraphqlQueryGetQuestionDetailVariables(
            title_slug=slug
        ),
        operation_name="getQuestionDetail",
    )


# actual query to the qpi
res = api_instance.graphql_post(body=get_request(question_slug))


# parse the response
cpp_snippet = [
    obj.code for obj in res.data.question.code_snippets if obj.lang == "C++"
][0]
question_id = "{:04d}".format(int(res.data.question.question_frontend_id))

# get question description and convert to markdown
desc = res.data.question.content
content_no_nbsp = "".join([x for x in desc.split('\n') if "nbsp" not in x])
content_md = "/*\n" + html2text(content_no_nbsp) + "\n*/\n\n"

# my desired cpp file template, containing
# question description,
# includes statements,
# the actual snippets from the api requests,
# the tests
_includes = '#include "leetcode.hpp"\n\n'
_snippets = "{S}\n\n".format(S=cpp_snippet)
_tests = 'TEST_CASE("{N}", "[{I}]"){{\n    Solution sol;\n    CHECK(true);\n}}'.format(
    N=question_slug, I=question_id
)

cpp_template = content_md + _includes + _snippets + _tests


# write the cpp template to file
filename = "{}-{}.cpp".format(question_id, question_slug)

# write to files
if os.path.isfile("./src/{}".format(filename)):
    print("{} already exists.".format(filename))
else:
    # create & write to file
    with open("./src/{}".format(filename), "w+") as f:
        f.write(cpp_template)

    # update CMakeLists.txt
    with open("./CMakeLists.txt", "a") as f:
        f.write("add_problem({} {})\n".format(question_id, question_slug))

    print("{} created.".format(filename))
