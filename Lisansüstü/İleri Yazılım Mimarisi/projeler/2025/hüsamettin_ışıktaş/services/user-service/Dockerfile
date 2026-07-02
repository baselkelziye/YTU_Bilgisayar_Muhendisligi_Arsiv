FROM node:18-alpine

WORKDIR /app

# Copy package files
COPY package*.json ./

# Install dependencies
RUN apk add --no-cache python3 make g++
RUN npm install

# Copy application files
COPY . .

# Change ownership to node user (non-root)
RUN chown -R node:node /app

# Switch to non-root user
USER node

EXPOSE 3001

CMD ["npm", "start"]
