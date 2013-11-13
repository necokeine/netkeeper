#ifndef RASDIAL_H
#define RASDIAL_H

#include <QDialog>

namespace Ui {
class rasdial;
}

class rasdial : public QDialog
{
    Q_OBJECT
    
public:
    explicit rasdial(QWidget *parent = 0);
    ~rasdial();
    virtual void accept();
    virtual void reject();
    
private:
    Ui::rasdial *ui;
};

#endif // RASDIAL_H
