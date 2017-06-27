#ifndef TEMPLATE_VIEW_HPP
#define TEMPLATE_VIEW_HPP

#include <gui/common/BaseView.hpp>
//#include <mvp/View.hpp>
#include <gui/widget/GaussianFrame.hpp>
#include <gui/template_screen/TemplatePresenter.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/Slider.hpp>

using namespace touchgfx;

/**
 * The View for a template screen. In the MVP paradigm, the view is a
 * passive interface that only displays the user interface and routes
 * any events from the user interface to the presenter. Normally it is the
 * responsibility of the presenter to act upon those events.
 *
 * By deriving from View, this class has a presenter pointer, which is configured
 * automatically.
 */
class TemplateView : public BaseView<TemplatePresenter>
{
public:
    /**
     * The view constructor. Note that the constructor runs before the new screen is
     * completely initialized, so do not place code here that causes anything to be drawn.
     * Use the setupScreen function instead.
     */
	TemplateView();
    virtual ~TemplateView() { }

    /**
     * This function is called automatically when the view is activated. This function
     * should add widgets to the root container, configure widget sizes and event
     * callbacks, et cetera.
     */
    virtual void setupScreen();

    /**
     * This function is called automatically when transitioning to a different screen
     * than this one. Can optionally be used to clean up.
     */
    virtual void tearDownScreen();

	void buttonClicked(const AbstractButton& source);

private:
	bool trigger;
	Button button;
	Image background;
	GaussianFrame frame;
	Slider slider;

	Callback<TemplateView, const AbstractButton&> buttonClickedCallback;
};

#endif // TEMPLATE_VIEW_HPP
