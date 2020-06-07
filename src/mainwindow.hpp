#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QLabel>
#include <QSettings>


#include "favouritecollection.hpp"
#include "geminirenderer.hpp"
#include "protocolsetup.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class BrowserTab;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication * app, QWidget *parent = nullptr);
    ~MainWindow();

    BrowserTab * addEmptyTab(bool focus_new, bool load_default);
    BrowserTab * addNewTab(bool focus_new, QUrl const & url);

    void setUrlPreview(QUrl const & url);

    void saveSettings();

public:
    FavouriteCollection favourites;

private slots:
    void on_browser_tabs_currentChanged(int index);

    void on_favourites_view_doubleClicked(const QModelIndex &index);

    void on_browser_tabs_tabCloseRequested(int index);

    void on_history_view_doubleClicked(const QModelIndex &index);

    void on_tab_titleChanged(QString const & title);

    void on_tab_locationChanged(QUrl const & url);

    void on_outline_view_clicked(const QModelIndex &index);

    void on_actionSettings_triggered();

    void on_actionNew_Tab_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionClose_Tab_triggered();

    void on_actionForward_triggered();

    void on_actionBackward_triggered();

    void on_actionRefresh_triggered();

    void on_actionAbout_Qt_triggered();

private:
    void reloadTheme();

public:
    QApplication * application;
    QSettings settings;
    GeminiStyle current_style;
    ProtocolSetup protocols;

private:
    Ui::MainWindow *ui;

    QLabel * url_status;
};
#endif // MAINWINDOW_HPP