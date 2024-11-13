#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QComboBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ajouterContact();
    void afficherContacts();
    void rechercherContact();
    void supprimerContact();
    void updateContact() ;

    void filtrerParCategorie();

    void on_pushButtonAjouter_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonRechercher_clicked();

    void on_Update_clicked();

    void on_comboBoxCategories_currentIndexChanged(int index);

    void on_comboBoxCategories_textActivated(const QString &arg1);

    void on_comboBoxCategories_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QComboBox *comboBoxCategories;

    void remplirComboBoxCategories();
    void connectToDatabase();
};



#endif // MAINWINDOW_H
