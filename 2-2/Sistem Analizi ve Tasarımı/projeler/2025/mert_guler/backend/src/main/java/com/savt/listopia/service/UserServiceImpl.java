package com.savt.listopia.service;

import com.savt.listopia.exception.APIException;
import com.savt.listopia.exception.userException.UserException;
import com.savt.listopia.exception.userException.UserNotAuthorizedException;
import com.savt.listopia.exception.userException.UserNotFoundException;
import com.savt.listopia.mapper.*;
import com.savt.listopia.model.user.User;
import com.savt.listopia.payload.dto.NotificationDTO;
import com.savt.listopia.payload.dto.UserActivityDTO;
import com.savt.listopia.payload.dto.UserDTO;
import com.savt.listopia.repository.*;
import com.savt.listopia.security.auth.AuthenticationToken;
import com.savt.listopia.service.user.UserActivityService;
import com.savt.listopia.util.PasswordUtil;
import com.savt.listopia.util.UserUtil;
import org.modelmapper.ModelMapper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;

import java.util.Optional;
import java.util.UUID;

@Service
public class UserServiceImpl implements UserService {
    private static final Logger LOGGER = LoggerFactory.getLogger(UserServiceImpl.class);

    private final UserRepository userRepository;
    private final ModelMapper modelMapper;
    private final UserMapper userMapper;
    private final UserActivityService userActivityService;
    private final NotificationService notificationService;
    private final SessionService sessionService;

    public UserServiceImpl(UserRepository userRepository, ModelMapper modelMapper, UserMapper userMapper, UserActivityService userActivityService, NotificationService notificationService, SessionService sessionService) {
        this.userRepository = userRepository;
        this.modelMapper = modelMapper;
        this.userMapper = userMapper;
        this.userActivityService = userActivityService;
        this.notificationService = notificationService;
        this.sessionService = sessionService;
    }

    @Override
    public UserDTO getUserByUsername(String username) {
        // User user = userRepository.findByUsername(username).orElseThrow(UserNotFoundException::new);
        User user = userRepository.findByUsernameLower(UserUtil.usernameToLowerCase(username)).orElseThrow(UserNotFoundException::new);
        return userMapper.toDTO(user);
    }

    @Override
    public User createUser(String firstname, String lastName, String email, String username, String hashedPassword) {
        if (userRepository.existsByUsernameLower(username))
            throw new APIException("username_already_exists");

        if (userRepository.existsByEmail(email))
            throw new APIException("email_already_exists");

        User user = new User();
        user.setEmail(email);
        user.setFirstName(firstname);
        user.setLastName(lastName);
        user.setUsername(username);
        user.setUsernameLower(UserUtil.usernameToLowerCase(username));
        user.setHashedPassword(hashedPassword);
        user.setCreatedAt( System.currentTimeMillis() );
        user.setLastOnline( System.currentTimeMillis() );
        user.setProfilePicture("https://i.pinimg.com/736x/c0/74/9b/c0749b7cc401421662ae901ec8f9f660.jpg");

        try {
            return userRepository.save(user);
        } catch (DataIntegrityViolationException e) {
            LOGGER.error("Error creating user", e);
            throw new APIException("username_or_email_already_exists");
        }
    }

    public UserDTO getUserById(Long id) {
        User user = userRepository.findById(id).orElseThrow(() -> new UserNotFoundException("user_does_not_exists"));
        return modelMapper.map(user, UserDTO.class);
    }

    public Optional<Long> getCurrentUserId() {
        Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
        if (authentication == null)
            return Optional.empty();

        if (authentication instanceof AuthenticationToken authenticationToken) {
            return Optional.of(authenticationToken.getPrincipal().getUserId());
        }

        return Optional.empty();
    }

    @Override
    public Long getCurrentUserIdOrThrow() {
        return getCurrentUserId().orElseThrow(UserNotAuthorizedException::new);
    }

    public void changeUsername(Long userId, String username) {
        if ( userRepository.existsByUsernameLower(UserUtil.usernameToLowerCase(username)) )
            throw new UserException("username_exists");

        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        user.setUsername(username);
        user.setUsernameLower(UserUtil.usernameToLowerCase(username));
        userRepository.save(user);
    }

    @Override
    public Long getUserIdFromUUID(UUID uuid) {
        return userRepository.findByUuid(uuid)
                .orElseThrow(() -> new UserNotFoundException("user_does_not_exists"))
                .getId();
    }

    @Override
    public void changePassword(Long userId, String password) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        user.setHashedPassword( PasswordUtil.hashPassword(password) );
        userRepository.save(user);
    }

    @Override
    public void changeBiography(Long userId, String biography) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        user.setBiography(biography);
        userRepository.save(user);
    }

    @Override
    public void deleteAccount(Long userId) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        user.setIsDeleted(true);
        userRepository.save(user);

        sessionService.deleteUserSessions(user);
    }

    @Override
    public void editUser(Long userId, UserDTO userNew) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);

        user.setUsername(userNew.getUsername());
        user.setUsernameLower(UserUtil.usernameToLowerCase(userNew.getUsername()));
        user.setFirstName(userNew.getFirstName());
        user.setLastName(userNew.getLastName());
        user.setBiography(userNew.getBiography());
        user.setRole(userNew.getRole());
        user.setProfilePicture(userNew.getProfilePicture());

        try {
            userRepository.save(user);
        } catch (RuntimeException e) {
            throw new APIException("unknown_database_error: " + e.getMessage() );
        }
    }

    @Override
    public Page<UserActivityDTO> getUserActivities(Long userId, int pageNumber, int pageSize) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        return userActivityService.getUserActivities(user, pageNumber, pageSize);
    }

    @Override
    public Page<NotificationDTO> getUserNotifications(Long userId, Integer pageNumber, Integer pageSize) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        return notificationService.getUserNotifications(user, pageNumber, pageSize);
    }

    @Override
    public void userNotifiedBefore(Long userId, Long timestamp) {
        User user = userRepository.findById(userId).orElseThrow(UserNotFoundException::new);
        notificationService.markAsRead(user, timestamp);
    }

    @Override
    public Page<UserDTO> searchUsers(String searchText, int pageNumber, int pageSize) {
        Pageable pageable = PageRequest.of(pageNumber, pageSize);
        Page<User> users = userRepository.searchUsers(searchText, pageable);
        return userMapper.toDTOPage(users);
    }

}
