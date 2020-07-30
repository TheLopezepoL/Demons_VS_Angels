#include "email.h"


Email::Email()
{

}

void Email::sendEmail(QString asunto, QString mensaje){
    // This is a first demo application of the SmtpClient for Qt project

    // First we need to create an SmtpClient object
    // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    // We need to set the username (your email address) and the password
    // for smtp authentification.

    smtp.setUser("CuentaDeDiositoParaLaProgra@gmail.com");
    smtp.setPassword("d5g247DHRhBsAvd");

    // Now we create a MimeMessage object. This will be the email.

    MimeMessage message;

    message.setSender(new EmailAddress("CuentaDeDiositoParaLaProgra@gmail.com", "Dios (TodoPoderoso)"));
    message.addRecipient(new EmailAddress("CuentaDeDiositoParaLaProgra@gmail.com", "Dios (Omnipresente)"));
    message.setSubject(asunto);

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText(mensaje);

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail

    smtp.connectToHost();
    smtp.login();
    if (smtp.sendMail(message))
        qDebug() << "CORREO ENVIADO EXITOSAMENTE";
    else
        qDebug() << "FALLO EL ENVIO DEL CORREO";
    smtp.quit();

}
