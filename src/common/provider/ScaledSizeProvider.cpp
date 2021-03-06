/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "ScaledSizeProvider.h"

namespace kImageAnnotator {

QSize ScaledSizeProvider::getScaledSize(const QSize &size)
{
	return { static_cast<int>(size.width() * getXScaleFactor()), static_cast<int>(size.height() * getYScaleFactor()) };
}

QRect ScaledSizeProvider::getScaledRect(const QRect &rect) {
    return getScaledRect(rect, getXScaleFactor(), getYScaleFactor());
}

QRect ScaledSizeProvider::getScaledRect(const QRect &rect, qreal scaleFactor) {
    return getScaledRect(rect, scaleFactor, scaleFactor);
}

QRect ScaledSizeProvider::getScaledRect(const QRect &rect, qreal xScaleFactor, qreal yScaleFactor) {
    return QRect(rect.left() * xScaleFactor, rect.top() * yScaleFactor, rect.width() * xScaleFactor, rect.height() * yScaleFactor);
}

QRect ScaledSizeProvider::getUnscaledRect(const QRect &rect) {
   return getUnscaledRect(rect, getXScaleFactor(), getYScaleFactor());
}

QRect ScaledSizeProvider::getUnscaledRect(const QRect &rect, qreal scaleFactor) {
   return getUnscaledRect(rect, scaleFactor, scaleFactor);
}

QRect ScaledSizeProvider::getUnscaledRect(const QRect &rect, qreal xScaleFactor, qreal yScaleFactor) {
    return QRect(rect.left() / xScaleFactor, rect.top() / yScaleFactor, rect.width() / xScaleFactor, rect.height() / yScaleFactor);
}

qreal ScaledSizeProvider::getXScaleFactor()
{
	auto desktopWidget = QApplication::desktop();
	return desktopWidget->logicalDpiX() / getReferenceDpiValue();
}

int ScaledSizeProvider::getScaledWidth(int width)
{
	return static_cast<int>(width * getXScaleFactor());
}

qreal ScaledSizeProvider::getYScaleFactor()
{
	auto desktopWidget = QApplication::desktop();
	return desktopWidget->logicalDpiY() / getReferenceDpiValue();
}

qreal ScaledSizeProvider::getReferenceDpiValue()
{
	return 96.0;
}

} // namespace kImageAnnotator
