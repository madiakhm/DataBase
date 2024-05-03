#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDialog>
#include <QTextEdit>
#include <QFont>
#include <QMessageBox>
#include <QSqlQuery>
#include <QStringList>
#include <dbmanager.h>

    class Visual : public QWidget
{
    Q_OBJECT

public:
    Visual(QWidget *parent = 0);

private:
    void setupUI();
    void connectSignalsAndSlots();

private slots:
    void addPerson();
    void removePerson();
    void printAll();
    void removeAll();
    void checkPersonExists();

private:
    QVBoxLayout *layout;
    QLabel *lineUp;
    QLineEdit *line;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *printButton;
    QPushButton *removeAllButton;
    QPushButton *checkExistsButton;
    DbManager *dbManager;
};

