#include "rasdial.h"
#include "ui_rasdial.h"
#include <fstream>
#include "source/dail.h"
#include <cstdlib>
#include <string>
#include <windows.h>
#include "ras.h"
#include "raserror.h"

#define _DATA_NAME "Netkeeper.dat"

rasdial::rasdial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rasdial)
{
    ui->setupUi(this);
    fstream fileUN(_DATA_NAME,ios::in);
    string temp;
    if (fileUN.good()){
        fileUN>>temp;
        ui->le1_username->clear();
        ui->le2_password->clear();
        ui->le1_username->insert(QString::fromLocal8Bit(temp.c_str()));
        fileUN>>temp;
        ui->le2_password->insert(QString::fromLocal8Bit(temp.c_str()));
        fileUN.close();
    }
    connect(ui->pb_login,SIGNAL(clicked(bool)),this, SLOT(accept()));
    connect(ui->pb_cancal,SIGNAL(clicked(bool)),this, SLOT(reject()));
}

rasdial::~rasdial()
{
    delete ui;
}
void rasdial::accept(){
    if ((ui->le1_username->text().length()==0) || (ui->le2_password->text().length()==0)){
        MessageBoxA(NULL,"no username or password","error",NULL);
        return ;
    }else{
        fstream fileout(_DATA_NAME,ios::out);
        fileout<<ui->le1_username->text().toStdString()<<endl;
        fileout<<ui->le2_password->text().toStdString()<<endl;
        fileout.close();
    }
    CXKUsername  user(ui->le1_username->text().toStdString());
    string sRealUsername;
    if (ui->check->checkState()){
        sRealUsername=user.Realusername();
    }else{
        sRealUsername=ui->le1_username->text().toStdString();
    }
    RASDIALPARAMS ras_now;
    HRASCONN handle = NULL;
    char line[256]="test_ras";
    RasValidateEntryName(NULL,line);
    ras_now.dwSize=sizeof(ras_now);
    strcpy(ras_now.szEntryName, line);
    strcpy(ras_now.szUserName,sRealUsername.c_str());
    strcpy(ras_now.szPassword, ui->le2_password->text().toStdString().c_str());
    DWORD dwRet=0;
    for (int i=0;i<10;i++){
        dwRet=RasDial(NULL,NULL,&ras_now,NULL,NULL,&handle);
        if (dwRet==0) break;
}
sprintf(line,"error code: %d",dwRet);
if (dwRet!=0){
    MessageBoxA(NULL,line,"error",NULL);
}else{
    MessageBoxA(NULL,"success","success",NULL);
        QDialog::accept();
        QDialog::close();
    }
}
void rasdial::reject(){
    QDialog::reject();
    QDialog::close();
}
