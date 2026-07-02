FROM node:18-alpine

WORKDIR /app

COPY package*.json ./

RUN npm install

COPY . .

# Change ownership to node user (non-root)
RUN chown -R node:node /app

# Switch to non-root user
USER node

EXPOSE 3003

CMD ["npm", "start"]
