"""
Copyright [2020] [RujikornN (devruji from Github's user)]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

from datetime import datetime
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

import ssl
import smtplib


def sending_emails(sender_id, sender_pass, receiver_id):
    try:
        mail_content = '''
                Hello,
                This is a simple mail. There is only text, no attachments are there The mail is sent using Python SMTP library.
                Thank You
                '''

        # The mail addresses and password
        sender_address = sender_id
        sender_pass = sender_pass
        receiver_address = receiver_id

        # Setup the MIME
        message = MIMEMultipart()
        message['From'] = sender_address
        message['To'] = receiver_address

        # The subject line
        message['Subject'] = 'A test mail sent by Python. It has an attachment.'

        # The body and the attachments for the mail
        message.attach(MIMEText(mail_content, 'plain'))

        # Create SMTP session for sending the mail
        session = smtplib.SMTP('smtp.gmail.com', 587)  # use gmail with port

        session.starttls()  # enable security

        # login with mail_id and password
        session.login(sender_address, sender_pass)
        text = message.as_string()
        session.sendmail(sender_address, receiver_address, text)
        session.quit()

        print(f'[INFO] : Email was sent')

    except Exception as e:
        print(f'[ERROR] : @ {e}')


if __name__ == '__main__':
    """
        Function desc. : Sending Emails With Python (Working only with Gmail on this function)
        Input params : ('your gmail username', 'password your gmail', 'receiver eamil') 

        If your found error due to : The Authentication Error can be because of your security settings, the 2-step verification for instance. It wont allow third party apps to override the authentication.

        Please following step below to hacking:
            Log in to your Google account, and use these links:
            Step 1 [Link of Disabling 2-step verification]:

            https://myaccount.google.com/security?utm_source=OGB&utm_medium=act#signin

            Step 2: [Link for Allowing less secure apps]

            https://myaccount.google.com/u/1/lesssecureapps?pli=1&pageId=none

            It should be all good now.
    """
    try:
        sending_emails('sender123@gmail.com', 'xxxxxxxx',
                       'receiver567@gmail.com')

    except Exception as e:
        print(f'[ERROR {datetime.now()}] : @{e}')
