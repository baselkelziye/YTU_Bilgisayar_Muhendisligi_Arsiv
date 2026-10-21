import select
import socket
import base64
import sys
import getpass
import hashlib
import os
import argparse
import signal


def instruction_commands_parser():
    parser = argparse.ArgumentParser(prog="PROG")
    subparsers = parser.add_subparsers()

    #create subparser for LOGIN_PAGE commands
    parser_login = subparsers.add_parser("\\login_info")
    parser_login.add_argument("info", type=str)
    parser_login.set_defaults(which="login_info")

    parser_nu = subparsers.add_parser("\\new_user_info")
    parser_nu.add_argument("info", type=str)
    parser_nu.set_defaults(which="new_user")

    #create subparsers for ROOM_SELECT
    parser_join = subparsers.add_parser("\\join_info")
    parser_join.add_argument("info", type=str)
    parser_join.add_argument("reason", nargs='?', type=str)
    parser_join.set_defaults(which="join_info")

    parser_showr = subparsers.add_parser("\\list_rooms_info")
    parser_showr.add_argument("info", type=str)
    parser_showr.add_argument("message", nargs='?', type=str)
    parser_showr.set_defaults(which="show_rooms_info")

    parser_create = subparsers.add_parser("\\create_room_info")
    parser_create.add_argument("info", type=str)
    parser_create.add_argument("reason", nargs='?', type=str)
    parser_create.set_defaults(which="create_room_info")

    #create subparser for CHAT_ROOM
    parser_chat = subparsers.add_parser("\\chat_info")
    parser_chat.add_argument("info", type=str)
    parser_chat.add_argument("username", nargs='?', type=str)
    parser_chat.add_argument("message", nargs='?', type=str)
    parser_chat.set_defaults(which="chat_info")

    parser_exit = subparsers.add_parser("\\exit_room_info")
    parser_exit.add_argument("info", type=str)
    parser_exit.set_defaults(which="exit_room_info")

    parser_logout = subparsers.add_parser("\\logout_info")
    parser_logout.add_argument("info", type=str)
    parser_logout.set_defaults(which="logout_info")

    return parser

def login_info(info, page):
    if info.info == "ok":
        sys.stdout.write("You can choose a chat room")
        return "ROOM_SELECT"
    else:
        sys.stdout.write("Your username or password is wrong.\n")
        show_login_menu()
        return page

def new_user_info(info, page):
    if info.info == "ok":
        sys.stdout.write("You are registered, you can login now")
    else:
        sys.stdout.write("Your username has taken.\n")
        show_login_menu()

    return page

def join_info(info, page):
    if info.info == "ok":
        sys.stdout.write("You joined the room.\n")
        return "CHAT_ROOM"
    else:
        if info.reason == "password":
            sys.stdout.write("Wrong password\n")
        elif info.reason == "name":
            sys.stdout.write("There is no chat room with that name.\n")
        elif info.reason == "users":
            sys.stdout.write("Chat room is full.Please retry later.\n")
        return page

def show_rooms_info(info, page):
    if info.info == "ok":
        chat_rooms = base64.b64decode(info.message.encode())
        sys.stdout.write(chat_rooms.decode())
        show_room_menu()
        general_prompt()
    else:
        sys.stdout.write("Unknown error")
    return page

def create_room_info(info, page):
    if info.info == "ok":
        sys.stdout.write("You have created the room.\n")
    else:
        if info.reason == "same_name":
            sys.stdout.write("There is same named chat room.Please try with different name.\n")
        elif info.reason == "long_name":
            sys.stdout.write("Name is too long.Max 17 characters.\n")
        elif info.reason == "user_limit":
            sys.stdout.write("Either too few or too many user limit.It must be between 4 and 221.\n")
    return page

def chat_info(info, page):
    if info.info == "pass":
        message = base64.b64decode(info.message.encode()).decode()
        message = "<{0}>: {1}\n".format(info.username, message)
        sys.stdout.write(message)
    else:
        sys.stdout.write("Unknown error")
    return page

def exit_room_info(info, page):
    if info.info == "ok":
        sys.stdout.write("Left chat room with success")
        return "ROOM_SELECT"
    else:
        sys.stdout.write("Unknown error")
        return page

def logout_info(info, page):
    if info.info == "ok":
        sys.stdout.write("Logout with success")
        return "LOGIN_PAGE"
    else:
        sys.stdout.write("Unknown error")
        return page

def return_info(parser, message, page):
    info_message_func = {"LOGIN_PAGE": {"login_info": login_info, "new_user_info": new_user_info},
                 "ROOM_SELECT": {"join_info": join_info, "show_rooms_info": show_rooms_info, "create_room_info": create_room_info, "logout_info": logout_info},
                 "CHAT_ROOM": {"chat_info": chat_info, "exit_room_info": exit_room_info, "logout_info": logout_info}}
    info = parser.parse_known_args(message.split(' '))[0]
    page = info_message_func[page][info.which](info, page)

    return page

def show_login_menu():
    sys.stdout.write("Please select index of option:\n1. Login\n2. Create Account\n")

def show_room_menu():
    sys.stdout.write("Please select index of option:\n1. Select Room\n2. Create Room\n3. Show Rooms\n")


def general_prompt():
    sys.stdout.write('<You> ')
    sys.stdout.flush()

def login_prompt(w, create=False):
    username = input("Username: ")
    password = getpass.getpass("Password: ")
    password_hash = hashlib.sha256(password.encode()).hexdigest()

    command = "\\new_user" if create else "\\login"

    os.write(w, "{2} {0} {1}\n".format(username, password_hash, command).encode())

def join_room_prompt(w):
    room_name = input("Room name: ")
    print("If there is no password for room then just hit enter.\n")
    password = getpass.getpass("Password: ")

    password_hash = hashlib.sha256(password.encode()).hexdigest() if password != '' else ''

    os.write(w, "\\join {0} {1}\n".format(room_name, password_hash).encode())

def create_room_prompt(w):
    room_name = input("Room name: ")
    print("If there is no password for room then just hit enter.\n")
    password = getpass.getpass("Password: ")
    print("If there is no room size then just hit enter.\n")
    print("Room size must be between 4 and 221\n")
    room_size = input("Room Size: ")

    os.write(w, "\\create_room {0} {1} {2}\n".format(room_name, password, room_size).encode())

def graceful_logout(signal, frame):
    socket = socket_list[2]
    socket.send(b"\\logout")


if __name__ == "__main__":
    if (len(sys.argv) < 3):
        print('Usage : python client.py hostname port')
        sys.exit()

    host = sys.argv[1]
    port = int(sys.argv[2])

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.settimeout(2)

    # connect to remote host
    try:
        server.connect((host, port))
    except:
        print('Unable to connect')
        sys.exit()

    print('Connected to remote host. Start sending messages')

    r_pipe, w_pipe = os.pipe()
    reader = os.fdopen(r_pipe)  #I need to write to stdin so i created another input stream

    info_parser = instruction_commands_parser()

    page = "LOGIN_PAGE"

    #login_prompt(w_pipe)
    show_login_menu()
    general_prompt()

    while 1:
        #reader sends data to server, data comes from server, input comes from stdin then prepare to send
        socket_list = [sys.stdin, reader, server]

        read_sockets, write_sockets, error_sockets = select.select(socket_list, [], [])

        for sock in read_sockets:
            # incoming message from remote server
            if sock == server:
                data = sock.recv(4096)
                if not data:
                    print('\nDisconnected from chat server')
                    sys.exit()
                else:
                    data = data.decode()
                    page = return_info(info_parser, data, page)

                    if page == "LOGIN_PAGE":
                        show_login_menu()

                    elif page == "ROOM_SELECT":
                        show_room_menu()
                    general_prompt()

            # send message
            elif sock == reader:
                msg = reader.readline().rstrip()
                server.send(msg.encode())
            else:   #user entered a message
                msg = sys.stdin.readline().rstrip() #delete \n
                if page == "LOGIN_PAGE":    #ifor every page, execute necessary input functions
                    if msg == "1":
                        login_prompt(w_pipe)
                    elif msg == "2":
                        login_prompt(w_pipe, create=True)
                    else:
                        sys.stdout.write("Select 1 or 2\n\n")
                        show_login_menu()
                elif page == "ROOM_SELECT":
                    if msg == "1":
                        join_room_prompt(w_pipe)
                    elif msg == "2":
                        create_room_prompt(w_pipe)
                    elif msg == "3":
                        os.write(w_pipe, b"\\show_rooms\n")
                    else:
                        sys.stdout.write("Select 1, 2 or 3\n\n")
                        show_room_menu()
                elif page == "CHAT_ROOM":
                    if msg == "": #we wouldn't want to send empty message
                        continue
                    msg_64_byte = base64.b64encode(msg.encode()).decode()
                    os.write(w_pipe, "\\chat {}\n".format(msg_64_byte).encode())
