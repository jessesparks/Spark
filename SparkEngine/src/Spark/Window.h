#pragma once
#include "SparkPCH.h"
#include "Spark/Core.h"
#include "Spark/Events/Event.h"
#include "Spark/Renderer/RenderContext.h"

namespace Spark
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Game made by Spark Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class SPARK_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
		inline RenderContext* GetRenderContext() { return m_Context; }
		inline virtual float GetTime() = 0;
		inline virtual void HideCursor() = 0;
		inline virtual void ShowCursor() = 0;
		inline virtual void ToggleCursor() = 0;
		inline bool IsCursorShown() const { return m_IsCursorShown; }

		static Window* Create(const WindowProps& props = WindowProps());
	protected:
		RenderContext* m_Context;
		bool m_IsCursorShown = true;
	};
}
