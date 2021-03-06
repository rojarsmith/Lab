#include <gui/template_screen/TemplateView.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include "GaussianBlur.h"
#include "touchgfx_evo.h"

TemplateView::TemplateView()
	:
	trigger(0),
	milliSecond(0),
	buttonClickedCallback(this, &TemplateView::buttonClicked)
{

}

void TemplateView::setupScreen()
{
	GaussianBlur * obj = new GaussianBlur();
	int a = obj->CalF(10);

	GaussianBlur2 * obj2 = new GaussianBlur2();
	int a2 = obj2->CalF(10);

	background.setBitmap(Bitmap(BITMAP_MATERIAL_WALLPAPER_GYP1_480X272_ID));
	add(background);

	slider.setBitmaps(
		Bitmap(BITMAP_FAT_SLIDER_BACKGROUND_282X45_ID),
		Bitmap(BITMAP_FAT_SLIDER_FILLED_282X45_ID),
		Bitmap(BITMAP_FAT_SLIDER_KNOB_37X29_ID)
		);
	slider.setXY(50, 100);
	slider.setupHorizontalSlider(0, 0, 8, 0, 236);
	slider.setValueRange(0, 100);
	slider.setTouchable(true);
	add(slider);


	frame.setVisible(false);
	add(frame);


	button.setBitmaps(Bitmap(BITMAP_OK_112X56_ID), Bitmap(BITMAP_OK_P_112X56_ID));
	button.setXY(50, 50);
	button.setAction(buttonClickedCallback);
	add(button);
}

void TemplateView::tearDownScreen()
{

}

void TemplateView::buttonClicked(const AbstractButton& source)
{
	trigger = trigger ? false : true;

	if (trigger)
	{
		frame.snap();
		frame.setVisible(true);		
		this->draw();
	}
	else{
		frame.setVisible(false);
		this->draw();
	}
}

void TemplateView::handleTimeUpdated(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	//currentSecondCounter = seconds;
	//currentMinuteCounter = minutes;
	////currentHourCounter counts from 0-59 due to the number of images of the hour hand
	//currentHourCounter = ((hours % 12) * 5) + (minutes / 12);

	//updateClock(currentHourCounter, currentMinuteCounter, currentSecondCounter);
}

void TemplateView::handleTimeUpdated(int millis)
{
	milliSecond = millis;
}

void TemplateView::handleTickEvent()
{
}