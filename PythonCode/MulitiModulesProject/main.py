from recv_msg import *
from handle_msg import *


def main():
    # 1. Receive message
    recv_msg()
    # 2. Test whether the messages are received
    test_recv_data()
    # 3. Determine that if processing is complete, receive additional data
    recv_msg_next()
    # 4. Processing messages
    handle_data()
    # 5. Whether the test is processed
    test_handle_data()
    # 6. Determine that if processing is complete, receive additional data
    recv_msg_next()


if __name__ == "__main__":
    main()
