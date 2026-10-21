CREATE TABLE media (
    media_id SERIAL PRIMARY KEY,
    image_name VARCHAR(255),
    image_type VARCHAR(255),
    image_byte BYTEA
);

-- USER Table
CREATE TABLE users (
    user_id SERIAL PRIMARY KEY,
    visible_name VARCHAR(255),
    username VARCHAR(255) UNIQUE NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    bio TEXT,
    user_password VARCHAR(255) NOT NULL,
    profile_photo_id INTEGER REFERENCES media(media_id),
    banner_photo_id INTEGER REFERENCES media(media_id),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- CATEGORY Table
CREATE TABLE category (
    category_id SERIAL PRIMARY KEY,
    category_name VARCHAR(255) UNIQUE NOT NULL
);

-- USER interested in CATEGORY
CREATE TABLE user_interest (
    user_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    category_id INTEGER REFERENCES category(category_id) ON DELETE CASCADE,
    PRIMARY KEY (user_id, category_id)
);

-- POST Table
CREATE TABLE post (
    post_id SERIAL PRIMARY KEY,
    user_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    content TEXT,
    media_id INTEGER REFERENCES media(media_id),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    homepage_visible boolean 
);

-- Post belongs to 0-N category 
CREATE TABLE post_category (
    post_id INTEGER REFERENCES post(post_id) ON DELETE CASCADE,
    category_id INTEGER REFERENCES category(category_id) ON DELETE CASCADE,
    PRIMARY KEY (post_id, category_id)
);
	

-- COMMENT Table
CREATE TABLE comment (
    comment_id SERIAL PRIMARY KEY,
    user_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    post_id INTEGER REFERENCES post(post_id) ON DELETE CASCADE,
    text TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- LIKE Table
CREATE TABLE post_like (
    user_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    post_id INTEGER REFERENCES post(post_id) ON DELETE CASCADE,
    PRIMARY KEY (user_id, post_id)
);

-- COMMUNITY Table
CREATE TABLE community (
    community_id SERIAL PRIMARY KEY,
    community_name VARCHAR(255) NOT NULL,
    community_description TEXT NOT NULL,
    media_id INTEGER REFERENCES media(media_id)
);

-- USER_COMMUNITY Table 
CREATE TABLE user_community (
    user_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    community_id INTEGER REFERENCES community(community_id) ON DELETE CASCADE,
    user_role VARCHAR(50) NOT NULL,
    PRIMARY KEY (user_id, community_id)
);

-- COMMUNITY POST relation
CREATE TABLE community_post (
    post_id INTEGER PRIMARY KEY REFERENCES post(post_id) ON DELETE CASCADE,
    community_id INTEGER REFERENCES community(community_id) ON DELETE CASCADE
);

-- USER Follow USER
CREATE TABLE user_follow (
    follower_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    followed_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    PRIMARY KEY (follower_id, followed_id),
    CHECK (follower_id <> followed_id) -- Cannot follow self
);

-- USER Block USER
CREATE TABLE user_block (
    blocker_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    blocked_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    PRIMARY KEY (blocker_id, blocked_id),
    CHECK (blocker_id <> blocked_id) -- Cannot block self
);
