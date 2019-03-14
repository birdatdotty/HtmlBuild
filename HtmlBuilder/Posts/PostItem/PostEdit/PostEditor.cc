#include "PostEditor.h"

#include <QApplication>


PostEditor::PostEditor(QString stCtx, QWidget *parent) :
  QWidget(parent),
  te(new QTextEdit(stCtx)),

  update(new QPushButton("update")),
  refresh(new QPushButton("refresh"))
{
  createTb();

  mainLayout.addWidget(te,0,0,1,2);
  mainLayout.addWidget(update, 1, 0);
  mainLayout.addWidget(refresh,1,1);

  setLayout(&mainLayout);

  connect(update, &QPushButton::released, [=]()
    {
      updateSignal(getHtml());

    });

  connect(te, &QTextEdit::currentCharFormatChanged,
          this, &PostEditor::currentCharFormatChanged);
  connect(te, &QTextEdit::cursorPositionChanged,
          this, &PostEditor::cursorPositionChanged);
  cursorPositionChanged();




  resize(800, 400);
}

QString PostEditor::getHtml() {
  QTextDocument *doc = te->document();
  QString html;
  for (QTextBlock currentBlock = doc->begin(); currentBlock != doc->end(); currentBlock = currentBlock.next()) {
      Qt::Alignment align = currentBlock.layout()->textOption().alignment();
      if (align == (Qt::AlignLeft | Qt::AlignAbsolute))
        html += "<p class='left'>";
      else if (align == Qt::AlignHCenter)
        html += "<p class='center'>";
      else if (align == (Qt::AlignRight | Qt::AlignAbsolute))
        html += "<p class='right'>";
      else if (align == Qt::AlignJustify)
        html += "<p class='justify'>";
      else html += "<p>";
    for (QTextBlock::iterator it = currentBlock.begin(); !(it.atEnd()); ++it)
      {
        QTextFragment currentFragment = it.fragment();
        if(currentFragment.charFormat().isImageFormat()) {
          QTextImageFormat imgFmt = currentFragment.charFormat().toImageFormat();
          QString image_name=imgFmt.name();
        }

        QTextCharFormat a = currentFragment.charFormat();
        bool italic = a.font().italic();
        bool bold = a.font().bold();
        QString words = currentFragment.text();
        if (italic)
          words = "<i>" + words + "</i>";

        if (bold)
          words = "<b>" + words + "</b>";

        html += words;
      }
      html += "</p>";
  }

  return html.simplified();
}

PostEditor::~PostEditor()
{
  delete te;
  delete update;
  delete refresh;
  delete menu;
  delete tb;
  delete actionAlignLeft;
  delete actionAlignCenter;
  delete actionAlignRight;
  delete actionAlignJustify;
  delete alignGroup;
}

void PostEditor::textBold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(actionTextBold->isChecked() ? QFont::Bold : QFont::Normal);
    mergeFormatOnWordOrSelection(fmt);
}

void PostEditor::textItalic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(actionTextItalic->isChecked());
    mergeFormatOnWordOrSelection(fmt);
}

void PostEditor::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = te->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    te->mergeCurrentCharFormat(format);
}

void PostEditor::fontChanged(const QFont &f)
{
    actionTextBold->setChecked(f.bold());
    actionTextItalic->setChecked(f.italic());
}

void PostEditor::addImg(QString img)
{
  QTextCursor cursor = te->textCursor();
  QTextDocument * doc = te->document();
  doc->addResource(QTextDocument::ImageResource, QUrl(img), img);
  cursor.insertImage(img);
}

void PostEditor::textAlign(QAction *a)
{
    if (a == actionAlignLeft)
        te->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
    else if (a == actionAlignCenter)
        te->setAlignment(Qt::AlignHCenter);
    else if (a == actionAlignRight)
        te->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
    else if (a == actionAlignJustify)
        te->setAlignment(Qt::AlignJustify);
}


QToolBar* PostEditor::getTb() {
  return tb;
}

QMenu* PostEditor::getMenuFormat() {
  return menu;
}

void PostEditor::currentCharFormatChanged(const QTextCharFormat &format)
{
    fontChanged(format.font());
}

void PostEditor::cursorPositionChanged() {
  alignmentChanged(te->alignment());
}

void PostEditor::alignmentChanged(Qt::Alignment a)
{
    if (a & Qt::AlignLeft) {
      actionAlignLeft->setChecked(true);
    }
    else if (a & Qt::AlignHCenter) {
        actionAlignCenter->setChecked(true);
    }
    else if (a & Qt::AlignRight) {
        actionAlignRight->setChecked(true);
    }
    else if (a & Qt::AlignJustify) {
        actionAlignJustify->setChecked(true);
    }
}

void PostEditor::createTb() {
  menu = new QMenu(tr("F&ormat")); //menuBar()->addMenu(tr("F&ormat"));

  tb = new QToolBar(this);
//  addToolBar(Qt::LeftToolBarArea,tb);
  tb->setMovable(false);

  //italic
  actionTextItalic = menu->addAction(QIcon(":/img/textitalic.png"), tr("&Italic"), this, &PostEditor::textItalic);
  actionTextItalic->setCheckable(true);
  tb->addAction(actionTextItalic);

  //bold
  actionTextBold = menu->addAction(QIcon(":/img/textbold.png"), tr("&Bold"), this, &PostEditor::textBold);
  actionTextBold->setCheckable(true);
  tb->addAction(actionTextBold);

  tb->addSeparator();







  menu->addSeparator();
  //left
  actionAlignLeft = new QAction(QIcon(":/img/textleft.png"), tr("&Left"), this);
  menu->addAction(actionAlignLeft);
  actionAlignLeft->setCheckable(true);

  tb->addAction(actionAlignLeft);

  //center
  actionAlignCenter = new QAction(QIcon(":/img/textcenter.png"), tr("&Center"), this);
  menu->addAction(actionAlignCenter);
  actionAlignCenter->setCheckable(true);
  tb->addAction(actionAlignCenter);

  //right
  actionAlignRight = new QAction(QIcon(":/img/textright.png"), tr("&Right"), this);
  menu->addAction(actionAlignRight);
  actionAlignRight->setCheckable(true);
  tb->addAction(actionAlignRight);


  //justify
  actionAlignJustify = new QAction(QIcon(":/img/textjustify.png"), tr("&Justify"), this);
  menu->addAction(actionAlignJustify);
  actionAlignJustify->setCheckable(true);
  tb->addAction(actionAlignJustify);

  // Make sure the alignLeft  is always left of the alignRight
  alignGroup = new QActionGroup(this);
  connect(alignGroup, &QActionGroup::triggered, this, &PostEditor::textAlign);

  if (QApplication::isLeftToRight()) {
      alignGroup->addAction(actionAlignLeft);
      alignGroup->addAction(actionAlignCenter);
      alignGroup->addAction(actionAlignRight);
  } else {
      alignGroup->addAction(actionAlignRight);
      alignGroup->addAction(actionAlignCenter);
      alignGroup->addAction(actionAlignLeft);
  }
  alignGroup->addAction(actionAlignJustify);

}
