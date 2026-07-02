# Frontend Implementation & Integration Documentation

This document provides a comprehensive guide for implementing the frontend application, detailing use cases, screen transitions, data flow, and API integration. It serves as a blueprint for developers to build a robust and seamless user experience.

## 1. Authentication Module

### 1.1 Login
*   **Goal:** Authenticate the user and start a session.
*   **Screen:** `Login.tsx`
*   **Transition:** `Login` -> `Dashboard` (on success) or `Register` (via link).
*   **API Endpoint:** `POST /api/users/login`
*   **Payload:**
    ```json
    {
      "email": "user@example.com",
      "password": "securepassword"
    }
    ```
*   **Data Flow:**
    1.  User enters credentials.
    2.  Frontend calls API.
    3.  **Success (200):**
        *   Store `token` in `localStorage`.
        *   Store `user` object in `localStorage` and `AuthContext`.
        *   Redirect to `/`.
    4.  **Error (401/400):** Display error message (e.g., "Invalid credentials").

### 1.2 Registration
*   **Goal:** Create a new user account.
*   **Screen:** `Register.tsx`
*   **Transition:** `Register` -> `Login` (or auto-login -> `Dashboard`).
*   **API Endpoint:** `POST /api/users/register`
*   **Payload:**
    ```json
    {
      "email": "user@example.com",
      "username": "user123",
      "password": "securepassword",
      "firstName": "John",
      "lastName": "Doe"
    }
    ```
*   **Data Flow:**
    1.  User fills registration form.
    2.  Frontend validates inputs (password length, email format).
    3.  Frontend calls API.
    4.  **Success (201):**
        *   (Optional) Auto-login using returned token.
        *   Redirect to `/login` with success toast.
    5.  **Error:** Show validation errors.

### 1.3 Logout
*   **Goal:** End the session securely.
*   **Screen:** `Dashboard` (Sidebar)
*   **Transition:** `Dashboard` -> `Login`.
*   **Action:**
    1.  User clicks "Logout" button.
    2.  Clear `token` and `user` from `localStorage` and `AuthContext`.
    3.  `socketService.disconnect()`.
    4.  Redirect to `/login`.

### 1.4 Session Restoration
*   **Goal:** Restore user session on page reload.
*   **Component:** `AuthContext.tsx`
*   **Logic:**
    1.  On mount, check `localStorage` for `token`.
    2.  If exists, call `GET /api/users/me` to validate and fetch fresh user data.
    3.  **Success:** Update `AuthContext` state.
    4.  **Error (401):** Clear storage and redirect to `/login`.

---

## 2. User & Profile Management

### 2.1 View/Edit My Profile
*   **Goal:** View current user details and update them.
*   **Screen:** Profile Modal (accessed from Sidebar Avatar).
*   **Endpoints:**
    *   Get: `GET /api/users/me`
    *   Update: `PUT /api/users/{userId}`
*   **Payload (Update):**
    ```json
    {
      "firstName": "John",
      "lastName": "Doe",
      "statusMessage": "Busy working",
      "profilePicture": "base64_or_url" // Optional
    }
    ```
*   **Data Flow:**
    1.  Prefill form with data from `AuthContext` or `/me` endpoint.
    2.  User updates fields and saves.
    3.  Call Update API.
    4.  **Success:** Update `AuthContext` with new data, show success toast.

### 2.2 Search Users
*   **Goal:** Find users to start a chat with.
*   **Screen:** `NewChatDialog`
*   **API Endpoint:** `GET /api/users/search?q={query}`
*   **Data Flow:**
    1.  User types in search bar (debounce 300ms).
    2.  Frontend calls API.
    3.  Display list of matching users (avatar, username, name).
    4.  User selects a user to start a Direct Chat.

---

## 3. Chat Management

### 3.1 List Chats
*   **Goal:** Display all active conversations.
*   **Screen:** `Dashboard` (Sidebar - `ChatList.tsx`)
*   **API Endpoint:** `GET /api/chats/user/me`
*   **Data Flow:**
    1.  On component mount, fetch chats.
    2.  Store in local state (`chats[]`).
    3.  Render list items.
    4.  **Real-time:** Listen for `CHAT_INVITE` or new message events to re-fetch/update list order (move active chat to top).

### 3.2 Start Direct Chat
*   **Goal:** Start a 1-on-1 conversation.
*   **Screen:** `NewChatDialog`
*   **API Endpoint:** `POST /api/chats/direct`
*   **Payload:** `{ "targetUserId": "uuid" }`
*   **Data Flow:**
    1.  Select user from search results.
    2.  Call API.
    3.  **Success:**
        *   Close dialog.
        *   Add new chat to `ChatList`.
        *   Select the new chat automatically.

### 3.3 Create Group Chat
*   **Goal:** Create a multi-user chat.
*   **Screen:** `NewChatDialog` (Group Tab)
*   **API Endpoint:** `POST /api/chats/group`
*   **Payload:**
    ```json
    {
      "name": "Team Project",
      "participantIds": ["id1", "id2"]
    }
    ```
*   **Data Flow:**
    1.  User selects multiple users from search.
    2.  User enters group name.
    3.  Call API.
    4.  **Success:** Update list and open chat.

### 3.4 Manage Group Participants
*   **Goal:** Add or remove members from a group.
*   **Screen:** Chat Details Modal (Group Settings).
*   **Endpoints:**
    *   Add: `POST /api/chats/{chatId}/participants` -> `{ "userId": "..." }`
    *   Remove: `DELETE /api/chats/{chatId}/participants/{userId}`
*   **Data Flow:**
    1.  Admin selects user to add/remove.
    2.  Call API.
    3.  **Success:** Refresh chat details/participant list.

---

## 4. Messaging

### 4.1 View Message History
*   **Goal:** See past conversation.
*   **Screen:** `Dashboard` (Message Area - `MessageList.tsx`)
*   **API Endpoint:** `GET /api/messages/chat/{chatId}?page=1&limit=50`
*   **Data Flow:**
    1.  When a chat is selected, fetch messages.
    2.  **Pagination:** Detect scroll to top -> fetch next page -> prepend messages.
    3.  **Display:** Group messages by date/sender for cleaner UI.

### 4.2 Send Text Message
*   **Goal:** Send a simple text.
*   **Screen:** `MessageInput.tsx`
*   **API Endpoint:** `POST /api/messages`
*   **Payload:**
    ```json
    {
      "chatId": "current_chat_id",
      "content": "Hello world",
      "messageType": "TEXT"
    }
    ```
*   **Data Flow:**
    1.  User types and hits Enter.
    2.  Call API.
    3.  **Optimistic UI:** Append message to list immediately with "Sending..." status.
    4.  **Success:** Update status to "Sent".

### 4.3 Send File/Image
*   **Goal:** Share media.
*   **Screen:** `MessageInput.tsx` (Attachment Button)
*   **Endpoints:**
    1.  Upload: `POST /api/files/upload` (multipart/form-data)
    2.  Send Msg: `POST /api/messages`
*   **Data Flow:**
    1.  User selects file.
    2.  Upload file -> Get `_id` or `url` from response.
    3.  Call Send Message API with `messageType: "IMAGE"` (or FILE) and `fileUrl`.

### 4.4 Real-time Updates
*   **Goal:** Receive messages instantly.
*   **Mechanism:** Socket.IO
*   **Event:** `notification` (type: `MESSAGE`)
*   **Logic:**
    1.  Listen for `notification` event.
    2.  Check if `notification.data.chatId` matches current open chat.
    3.  **Match:** Append new message / Re-fetch messages.
    4.  **No Match:** Increment unread badge on Chat List item.

### 4.5 Edit Message
*   **Goal:** Correct a typo.
*   **Screen:** Message Context Menu -> Edit Mode.
*   **API Endpoint:** `PUT /api/messages/{messageId}`
*   **Payload:** `{ "content": "Corrected text" }`
*   **Logic:**
    1.  User selects "Edit".
    2.  Input field populates with old text.
    3.  User saves.
    4.  Call API.
    5.  Update message in list locally.

### 4.6 Delete Message
*   **Goal:** Remove a message.
*   **Screen:** Message Context Menu -> Delete.
*   **API Endpoint:** `DELETE /api/messages/{messageId}`
*   **Logic:**
    1.  User confirms deletion.
    2.  Call API.
    3.  Remove message from local list or mark as "This message was deleted".

---

## 5. Notifications

### 5.1 Global Notifications
*   **Goal:** Alert user of events (new chat, etc.).
*   **Screen:** Dashboard Header / Toast.
*   **API Endpoint:** `GET /api/notifications`
*   **Logic:**
    1.  Fetch unread notifications on load.
    2.  Show notification bell with badge count.
    3.  **Mark Read:** `PUT /api/notifications/{id}/read` when user clicks/views it.

## 6. Error Handling & Edge Cases

*   **Network Errors:** Show "Check internet connection" toast.
*   **401 Unauthorized:** Redirect to Login immediately (handled by Axios interceptor).
*   **403 Forbidden:** Show "You don't have permission" toast (e.g., non-admin removing participant).
*   **404 Not Found:** If a chat/message no longer exists, refresh the view.

