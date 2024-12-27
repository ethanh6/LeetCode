FROM node:20-slim as base

WORKDIR /usr/src/app

COPY package.json package-lock.json ./

RUN npm install --silent

RUN apt-get update

COPY . ./


# development stage
FROM base as development

RUN npm install

EXPOSE 3000

CMD ["npm", "start"]


# production stage
FROM base as production

RUN npm run build

RUN npm install -g serve

EXPOSE 3000

CMD ["serve", "-s", "build", "-l", "3000"]

