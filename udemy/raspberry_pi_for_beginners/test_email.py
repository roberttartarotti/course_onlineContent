# Robert Tartarotti, 2022-07-30
# Test E-mail


import yagmail


def get_password():
    """ Get the password from the system """
    password = ""
    with open("/home/robert/.local/share/.email_password", "r") as f:
        password = f.read()
    return password


def send_email(to, subject, contents, attachments=None):
    """ Send the E-mail to someone """
    yag = yagmail.SMTP("scadmuw.dot@gmail.com", get_password())
    if attachments:
        yag.send(to=to, subject=subject, contents=contents, attachments=attachments)
    else:
        yag.send(to=to, subject=subject, contents=contents)
    print("Email sent to " + to)


def main():
    att = "/home/robert/Desktop/online_courses_git/udemy/raspberry_pi_for_beginners/file_to_send.txt"
    send_email("robert.tartarotti@gmail.com", "first E-mail", "Hello from Raspberry Pi", att)


try:
    main()
except KeyboardInterrupt:
    sys.exit(0)