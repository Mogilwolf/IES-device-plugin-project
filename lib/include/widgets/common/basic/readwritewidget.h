#ifndef SYNCSYS_DEVICE_WIDGET_WIDGETS_COMMON_BASIC_READWRITEWIDGET_H_
#define SYNCSYS_DEVICE_WIDGET_WIDGETS_COMMON_BASIC_READWRITEWIDGET_H_

class ReadWriteWidget {
 public:
  virtual void setReadOnlyMode(bool status) = 0;
};

#endif /* SYNCSYS_DEVICE_WIDGET_WIDGETS_COMMON_BASIC_READWRITEWIDGET_H_ */