#include "visual.h"
#include "dbmanager.h"

   Visual::Visual(QWidget *parent) : QWidget(parent) {
    setupUI();
    connectSignalsAndSlots();
   QString pathToDatabase = "C:/Users/Hp/Desktop/DataBase/database/people.db";

    dbManager = new DbManager(pathToDatabase);

    setFixedSize(350, 390);
}

void Visual::setupUI() {
    layout = new QVBoxLayout(this);
    layout->setSpacing(3);
    setStyleSheet("background-color: #FF6666;");

    lineUp = new QLabel("Name:", this);
    lineUp->setStyleSheet("QLabel { font-size: 18px; color: black; }");

    line = new QLineEdit(this);
    line->setStyleSheet("QLineEdit { width: 200px; height: 40px; color: black; background-color: #FFCCCC;}");

    addButton = new QPushButton("Add", this);
    addButton->setStyleSheet("QPushButton { width: 150px; height: 50px; background-color: #FFCCCC; color: black; }");

    removeButton = new QPushButton("Remove", this);
    removeButton->setStyleSheet("QPushButton { width: 150px; height: 50px; background-color: #FFCCCC; color: black; }");

    printButton = new QPushButton("Print All", this);
    printButton->setStyleSheet("QPushButton { width: 150px; height: 50px; background-color: #FFCCCC; color: black;}");

    removeAllButton = new QPushButton("Remove All", this);
    removeAllButton->setStyleSheet("QPushButton { width: 150px; height: 50px; background-color: #FFCCCC; color: black; }");

    checkExistsButton = new QPushButton("Check Exists", this);
    checkExistsButton->setStyleSheet("QPushButton { width: 150px; height: 50px; background-color: #FFCCCC; color: black;}");


    QFont buttonFont = addButton->font();
    buttonFont.setPointSize(12);
    addButton->setFont(buttonFont);
    removeButton->setFont(buttonFont);
    printButton->setFont(buttonFont);
    removeAllButton->setFont(buttonFont);
    checkExistsButton->setFont(buttonFont);

    layout->addWidget(lineUp);
    layout->addWidget(line);
    layout->addWidget(addButton);
    layout->addWidget(removeButton);
    layout->addWidget(printButton);
    layout->addWidget(removeAllButton);
    layout->addWidget(checkExistsButton);

    setLayout(layout);
}

void Visual::connectSignalsAndSlots() {
    connect(addButton, &QPushButton::clicked, this, &Visual::addPerson);
    connect(removeButton, &QPushButton::clicked, this, &Visual::removePerson);
    connect(printButton, &QPushButton::clicked, this, &Visual::printAll);
    connect(removeAllButton, &QPushButton::clicked, this, &Visual::removeAll);
    connect(checkExistsButton, &QPushButton::clicked, this, &Visual::checkPersonExists);
}

void Visual::addPerson() {
    QString name = line->text();
    if (!name.isEmpty()) {
        if (dbManager->addPerson(name)) {
            QMessageBox::information(this, "Success", "Person added successfully.");
            line->clear();
        } else {
            QMessageBox::warning(this, "Error", "Failed to add person.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a name.");
    }
}

void Visual::removePerson() {
    QString name = line->text();
    if (!name.isEmpty()) {
        if (dbManager->removePerson(name)) {
            QMessageBox::information(this, "Success", "Person removed successfully.");
            line->clear();
        } else {
            QMessageBox::warning(this, "Error", "Failed to remove person.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a name.");
    }
}

void Visual::printAll() {
    QDialog *printAllDialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(printAllDialog);

    QStringList records;
    QSqlQuery query("SELECT * FROM people");
    while (query.next()) {
        QString name = query.value("name").toString();
        records.append(name);
    }

    QString allRecordsText = "People in db: \n";
    for (const QString& record : records) {
        allRecordsText += " " + record + "; \n";
    }

    QTextEdit *textEdit = new QTextEdit(printAllDialog);
    textEdit->setPlainText(allRecordsText);
    textEdit->setReadOnly(true);

    layout->addWidget(textEdit);

    QFont font;
    font.setPointSize(12);
    textEdit->setFont(font);

    printAllDialog->setWindowTitle("All Records");
    printAllDialog->resize(600, 400);

    printAllDialog->exec();
}

void Visual::removeAll() {
    if (dbManager->removeAll()) {
        QMessageBox::information(this, "Success", "All records removed successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to remove all records.");
    }
}

void Visual::checkPersonExists() {
    QString name = line->text();
    if (!name.isEmpty()) {
        if (dbManager->personExists(name)) {
            QMessageBox::information(this, "Result", "Person exists.");
        } else {
            QMessageBox::information(this, "Result", "Person does not exist.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a name.");
    }
}
