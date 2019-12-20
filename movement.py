import time
import serial
import smtplib

TO = 'send to email goes here'
GMAIL_USER = 'send from email goes here'
GMAIL_PASS = 'password for email to send from'

SUBJECT = 'You have (snail) mail!'
TEXT = 'Movement was detected inside your mailbox.'
ser = serial.Serial('COM3', 9600)



def send_email():
    print("Sending Email")
    smtpserver = smtplib.SMTP("smtp.gmail.com",587)
    smtpserver.ehlo()
    smtpserver.starttls()
    smtpserver.ehlo
    smtpserver.login(GMAIL_USER, GMAIL_PASS)
    header = 'To:' + TO + '\n' + 'From: ' + GMAIL_USER
    header = header + '\n' + 'Subject:' + SUBJECT + '\n'
    print(header)
    msg = header + '\n' + TEXT + ' \n\n'
    smtpserver.sendmail(GMAIL_USER, TO, msg)
    smtpserver.close()

while True:
    message = ser.readline()
    print(message)
    if message != '' :
        send_email()
    time.sleep(0.5)
