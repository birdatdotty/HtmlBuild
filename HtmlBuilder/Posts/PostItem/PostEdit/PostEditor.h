#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QGridLayout>
#include <QTextBlock>
#include <QPushButton>
#include <QToolBar>
#include <QMenu>

namespace Ui {
  class Widget;
}

class PostEditor : public QWidget
{
  Q_OBJECT

  public:
    explicit PostEditor(QString stCtx, QWidget *parent = nullptr);
    ~PostEditor();
    QToolBar* getTb();
    QMenu* getMenuFormat();


  private:
    QMenu *menu;
    QGridLayout mainLayout;
    Ui::Widget *ui;
    QTextEdit *te;
    QPushButton *update,
                *refresh;

    QString stImg;
    QToolBar *tb;

//    Widget *widget;
    QAction *actionTextBold;
    QAction *actionTextItalic;
    QAction *actionAlignLeft;
    QAction *actionAlignCenter;
    QAction *actionAlignRight;
    QAction *actionAlignJustify;
    QActionGroup *alignGroup;

    QString getHtml();
    void createTb();

public slots:
    void textBold();
    void textItalic();
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void fontChanged(const QFont &f);
    void addImg(QString path);

private slots:
    void currentCharFormatChanged(const QTextCharFormat &format);
    void textAlign(QAction *a);
    void cursorPositionChanged();
    void alignmentChanged(Qt::Alignment a);

signals:
    void updateSignal(QString);
};

#endif // EDITOR_H
