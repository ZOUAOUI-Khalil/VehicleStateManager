#ifndef TYPESANDDEFINES_H
#define TYPESANDDEFINES_H

#include <QString>



 struct Configuration{
    int QOS;
    int Port;
    int SecurityLevel;
    QString Username;
    QString Password;
    QString Host;
    QString Topic;
    QString Certif;
};


struct TGURMsg{
    long timestamp;
    long TransmissionPeriod;
    long SerialNumber ;
    long  long IMEI;
    QString NetworkStatus;
    int SignalStrength;
    int DiagnosticStatus;
    int APC;
    QString VIN;
    operator==(const TGURMsg &  Msg) const {
        return SerialNumber == Msg.SerialNumber;
    }

    //Current Memory:
    int RowInWindow;

};


#endif // TYPESANDDEFINES_H
