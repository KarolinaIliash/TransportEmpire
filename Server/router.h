#pragma once

#include "controller.h"
#include "testcontroller.hpp"

#include <vector>

#include <QObject>
#include <QVector>

class Router : public QObject
{
	Q_OBJECT
private:
	QVector<IController*> controls;

public:
	explicit Router(QObject *parent = 0);
	~Router();

public:
	void addController(IController* controller);
	void addControllers(QVector<IController*> controls);

	static Router* createDefault();

public slots:
	void onRequestReceived(const Request& request);

signals:
	void requestReceived(const Request& request);
	void replyReady(const Reply& reply);
};

