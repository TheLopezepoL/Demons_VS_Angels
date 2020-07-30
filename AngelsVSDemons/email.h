#ifndef EMAIL_H
#define EMAIL_H
#include "SmtpMime"


struct Email
{
    Email();

    static void sendEmail(QString asunto, QString mensaje);
};

#endif // EMAIL_H
