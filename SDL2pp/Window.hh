/*
  libSDL2pp - C++11 bindings/wrapper for SDL2
  Copyright (C) 2013-2015 Dmitry Marakasov <amdmi3@amdmi3.ru>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SDL2PP_WINDOW_HH
#define SDL2PP_WINDOW_HH

#include <string>

#include <SDL2/SDL_stdinc.h>

#include <SDL2pp/Point.hh>

struct SDL_Window;

namespace SDL2pp {

////////////////////////////////////////////////////////////
/// \brief GUI window object
///
/// \ingroup windows
///
/// \headerfile SDL2pp/Window.hh
///
/// SDL2pp::Window is a wrapper around SDL_Window structure
/// and related functions which take care of GUI window
/// management.
///
/// Usage example:
/// \code
/// {
///     SDL2pp::SDL sdl(SDL_INIT_VIDEO);
///     SDL2pp::Window window("Test Window",
///                           SDL_WINDOWPOS_UNDEFINED,
///                           SDL_WINDOWPOS_UNDEFINED,
///                           640,
///                           480,
///                           SDL_WINDOW_OPENGL);
///
///     SDL_Delay(3000); // show window for 3 seconds
/// }
/// \endcode
///
////////////////////////////////////////////////////////////
class Window {
private:
	SDL_Window* window_; ///< Managed SDL2_Window object

public:
	////////////////////////////////////////////////////////////
	/// \brief Construct from existing SDL_Window structure
	///
	/// \param[in] window Existing SDL_Window to manage
	///
	////////////////////////////////////////////////////////////
	Window(SDL_Window* window);

	////////////////////////////////////////////////////////////
	/// \brief Create window with specified title and dimensions
	///
	/// \param[in] title Title of the windows, in UTF-8 encoding
	/// \param[in] x X position of the window, SDL_WINDOWPOS_CENTERED, or SDL_WINDOWPOS_UNDEFINED
	/// \param[in] y X position of the window, SDL_WINDOWPOS_CENTERED, or SDL_WINDOWPOS_UNDEFINED
	/// \param[in] w Width of the window
	/// \param[in] h Height of the window
	/// \param[in] flags 0 or more SDL_WindowFlags OR'd together
	///
	/// \throws SDL2pp::Exception
	///
	/// \see http://wiki.libsdl.org/SDL_CreateWindow
	///
	////////////////////////////////////////////////////////////
	Window(const std::string& title, int x, int y, int w, int h, Uint32 flags);

	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	/// \see http://wiki.libsdl.org/SDL_DestroyWindow
	///
	////////////////////////////////////////////////////////////
	virtual ~Window();

	////////////////////////////////////////////////////////////
	/// \brief Move constructor
	///
	/// \param[in] other SDL2pp::Window object to move data from
	///
	////////////////////////////////////////////////////////////
	Window(Window&& other) noexcept;

	////////////////////////////////////////////////////////////
	/// \brief Move assignment operator
	///
	/// \param[in] other SDL2pp::Window object to move data from
	///
	/// \returns Reference to self
	///
	////////////////////////////////////////////////////////////
	Window& operator=(Window&& other) noexcept;

	////////////////////////////////////////////////////////////
	/// \brief Deleted copy constructor
	///
	/// This class is not copyable
	///
	////////////////////////////////////////////////////////////
	Window(const Window& other) = delete;

	////////////////////////////////////////////////////////////
	/// \brief Deleted assignment operator
	///
	/// This class is not copyable
	///
	////////////////////////////////////////////////////////////
	Window& operator=(const Window& other) = delete;

	////////////////////////////////////////////////////////////
	/// \brief Get pointer to managed SDL_Window structure
	///
	/// \returns Pointer to managed SDL_Window structure
	///
	////////////////////////////////////////////////////////////
	SDL_Window* Get() const;

	////////////////////////////////////////////////////////////
	/// \brief Get dimensions of the window
	///
	/// \returns SDL2pp::Point representing dimensions (width and
	///          height) of the window in pixels
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowSize
	///
	////////////////////////////////////////////////////////////
	Point GetSize() const;

	////////////////////////////////////////////////////////////
	/// \brief Get width of the window
	///
	/// \returns Width of the window in pixels
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowSize
	///
	////////////////////////////////////////////////////////////
	int GetWidth() const;

	////////////////////////////////////////////////////////////
	/// \brief Get height of the window
	///
	/// \returns Height of the window in pixels
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowSize
	///
	////////////////////////////////////////////////////////////
	int GetHeight() const;

	////////////////////////////////////////////////////////////
	/// \brief Set window title
	///
	/// \param[in] title New window title in UTF-8 encoding
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowTitle
	///
	////////////////////////////////////////////////////////////
	void SetTitle(const std::string& title);

	////////////////////////////////////////////////////////////
	/// \brief Get window title
	///
	/// \returns Title of the window in UTF-8 format or "" if there is no title
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowTitle
	///
	////////////////////////////////////////////////////////////
	std::string GetTitle() const;

	////////////////////////////////////////////////////////////
	/// \brief Make a window as large as possible
	///
	/// \see http://wiki.libsdl.org/SDL_MaximizeWindow
	///
	////////////////////////////////////////////////////////////
	void Maximize();

	////////////////////////////////////////////////////////////
	/// \brief Minimize a window to an iconic representation
	///
	/// \see http://wiki.libsdl.org/SDL_MinimizeWindow
	///
	////////////////////////////////////////////////////////////
	void Minimize();

	////////////////////////////////////////////////////////////
	/// \brief Hide a window
	///
	/// \see http://wiki.libsdl.org/SDL_HideWindow
	///
	////////////////////////////////////////////////////////////
	void Hide();

	////////////////////////////////////////////////////////////
	/// \brief Restore the size and position of a minimized or maximized window
	///
	/// \see http://wiki.libsdl.org/SDL_RestoreWindow
	///
	////////////////////////////////////////////////////////////
	void Restore();

	////////////////////////////////////////////////////////////
	/// \brief Raise a window above other windows and set the input focus
	///
	/// \see http://wiki.libsdl.org/SDL_RaiseWindow
	///
	////////////////////////////////////////////////////////////
	void Raise();

	////////////////////////////////////////////////////////////
	/// \brief Show a window
	///
	/// \see http://wiki.libsdl.org/SDL_ShowWindow
	///
	////////////////////////////////////////////////////////////
	void Show();

	////////////////////////////////////////////////////////////
	/// \brief Set a window's fullscreen state
	///
	/// \param[in] flags SDL_WINDOW_FULLSCREEN, SDL_WINDOW_FULLSCREEN_DESKTOP or 0
	///
	/// \throws SDL2pp::Exception
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowFullscreen
	///
	////////////////////////////////////////////////////////////
	void SetFullscreen(int flags);

	////////////////////////////////////////////////////////////
	/// \brief Set the size of a window's client area
	///
	/// \param[in] w Width of the window in pixels
	/// \param[in] h Height of the window in pixels
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowSize
	///
	////////////////////////////////////////////////////////////
	void SetSize(int w, int h);

	////////////////////////////////////////////////////////////
	/// \brief Set the size of a window's client area
	///
	/// \param[in] size Point representing window dimensions
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowSize
	///
	////////////////////////////////////////////////////////////
	void SetSize(const Point& size);

	////////////////////////////////////////////////////////////
	/// \brief Get the brightness (gamma multiplier) for the display that owns a given window
	///
	/// \returns Brightness for the display where 0.0 is completely dark and 1.0 is normal brightness
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowBrightness
	///
	////////////////////////////////////////////////////////////
	float GetBrightness() const;

	////////////////////////////////////////////////////////////
	/// \brief Set the brightness (gamma multiplier) for the display that owns a given window
	///
	/// \param[in] brightness Brightness value to set where 0.0 is completely dark and 1.0 is normal brightness
	///
	/// \throws SDL2pp::Exception
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowBrightness
	///
	////////////////////////////////////////////////////////////
	void SetBrightness(float brightness);

	////////////////////////////////////////////////////////////
	/// \brief Get the position of a window
	///
	/// \returns Point representing window position
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowPosition
	///
	////////////////////////////////////////////////////////////
	Point GetPosition() const;

	////////////////////////////////////////////////////////////
	/// \brief Set the position of a window
	///
	/// \param[in] x X coordinate of the window, SDL_WINDOWPOS_CENTERED, or SDL_WINDOWPOS_UNDEFINED
	/// \param[in] y Y coordinate of the window, SDL_WINDOWPOS_CENTERED, or SDL_WINDOWPOS_UNDEFINED
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowPosition
	///
	////////////////////////////////////////////////////////////
	void SetPosition(int x, int y);

	////////////////////////////////////////////////////////////
	/// \brief Set the position of a window
	///
	/// \param[in] pos Point representin position of the a window
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowPosition
	///
	////////////////////////////////////////////////////////////
	void SetPosition(const Point& pos);

	////////////////////////////////////////////////////////////
	/// \brief Get the minimum size of a window's client area
	///
	/// \returns Point representing minimum area of window's client area
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowMinimumSize
	///
	////////////////////////////////////////////////////////////
	Point GetMinimumSize() const;

	////////////////////////////////////////////////////////////
	/// \brief Set the minimum size of a window's client area
	///
	/// \param[in] w Minimum width of the window in pixels
	/// \param[in] h Minimum height of the window in pixels
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowMinimumSize
	///
	////////////////////////////////////////////////////////////
	void SetMinimumSize(int w, int h);

	////////////////////////////////////////////////////////////
	/// \brief Set the minimum size of a window's client area
	///
	/// \param[in] size Minimum area of the window in pixels
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowMinimumSize
	///
	////////////////////////////////////////////////////////////
	void SetMinimumSize(const Point& size);

	////////////////////////////////////////////////////////////
	/// \brief Get the maximum size of a window's client area
	///
	/// \returns Point representing maximum area of window's client area
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowMaximumSize
	///
	////////////////////////////////////////////////////////////
	Point GetMaximumSize() const;

	////////////////////////////////////////////////////////////
	/// \brief Set the maximum size of a window's client area
	///
	/// \param[in] w Maximum width of the window in pixels
	/// \param[in] h Maximum height of the window in pixels
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowMaximumSize
	///
	////////////////////////////////////////////////////////////
	void SetMaximumSize(int w, int h);

	////////////////////////////////////////////////////////////
	/// \brief Set the maximum size of a window's client area
	///
	/// \param[in] size Maximum area of the window in pixels
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowMaximumSize
	///
	////////////////////////////////////////////////////////////
	void SetMaximumSize(const Point& size);

	////////////////////////////////////////////////////////////
	/// \brief Get a window's input grab mode
	///
	/// \returns True if input is grabbed, flase otherwise
	///
	/// \see http://wiki.libsdl.org/SDL_GetWindowGrab
	///
	////////////////////////////////////////////////////////////
	bool GetGrab() const;

	////////////////////////////////////////////////////////////
	/// \brief Set a window's input grab mode
	///
	/// \param[in] grabbed True to grab input, false to release input
	///
	/// \see http://wiki.libsdl.org/SDL_SetWindowGrab
	///
	////////////////////////////////////////////////////////////
	void SetGrab(bool grabbed);
};

}

#endif
