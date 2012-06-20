#include <QAction>
#include <QNetworkRequest>
#include <QDesktopServices>
#include "rsslisting.h"
#include "webpage.h"

WebPage::WebPage(QWidget *parent) :
  QWebPage(parent)
{
  action(QWebPage::OpenFrameInNewWindow)->setVisible(false);
  action(QWebPage::DownloadLinkToDisk)->setVisible(false);
  action(QWebPage::OpenImageInNewWindow)->setVisible(false);
  action(QWebPage::DownloadImageToDisk)->setVisible(false);
}

bool WebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type)
{
  return QWebPage::acceptNavigationRequest(frame,request,type);
}

QWebPage *WebPage::createWindow(WebWindowType type)
{
  Q_UNUSED(type)

  QObject *parent_ = parent();
  while(parent_->parent()) {
    parent_ = parent_->parent();
  }
  RSSListing *rsslisting_ = qobject_cast<RSSListing*>(parent_);

  return rsslisting_->createWebTab();
}