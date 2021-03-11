FROM node:12-alpine
WORKDIR /app
COPY package*.json ./
RUN npm install
EXPOSE 80
COPY . .
CMD ["node", "server.js"]
