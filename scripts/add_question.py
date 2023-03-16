from typing import List
import os
import leetcode
import leetcode.auth
from dotenv import load_dotenv


load_dotenv()


# sample question URL
# https://leetcode.com/problems/longest-common-subsequence/
# https://leetcode.com/problems/two-sum/description/
# get questioni slug form question url
question_slug = input("Question URL? ").split("/")[4]


# Get the leetcode_session token from browser, and put it into .env
leetcode_session = os.getenv('LEETCODE_SESSION')


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
get_request = lambda slug: leetcode.GraphqlQuery(
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
    variables=leetcode.GraphqlQueryGetQuestionDetailVariables(title_slug=slug),
    operation_name="getQuestionDetail",
)


# actual query to the qpi
res = api_instance.graphql_post(body=get_request(question_slug))


# parse the response
cpp_snippet = [obj.code for obj in res.data.question.code_snippets if obj.lang == "C++"][0]
question_id = res.data.question.question_frontend_id


# my desired cpp file template, containing includes statements,
# the actual snippets from the api requests and the test statements
_includes = '#include "Leetcode.hpp"\n\n'
_snippets = "{S}\n\n".format(S=cpp_snippet)
_tests = 'TEST_CASE("{N}", "[{I}]"){{\n    Solution s;\n\n}}'.format(N=question_slug, I=question_id)

cpp_template = _includes + _snippets + _tests


# write the cpp template to file
id_slug = "{:04d}-{}".format(int(question_id), question_slug)
attempts = 0

# update attempts if the question is done more than once
while os.path.isfile("./src/{}-{}.cpp".format(id_slug, attempts)):
    attempts += 1

with open("./src/{}-{}.cpp".format(id_slug, attempts), "w+") as f:
    f.write(cpp_template)

print("Question: {} already has {} attempts.".format(question_id, attempts))
print("./src/{}-{}.cpp created.".format(id_slug, attempts))



