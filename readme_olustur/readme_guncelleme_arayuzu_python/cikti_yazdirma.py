import sys


def custom_write(message):
    sys.stdout.write(message)
    sys.stdout.flush()


def custom_write_error(message):
    sys.stderr.write(message)
    sys.stderr.flush()
