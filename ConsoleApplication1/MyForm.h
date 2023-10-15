#pragma once
#include "src/entidades/Controller.hpp"

namespace ConsoleApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Controller^ controller;
		Graphics^ graficador;
	private: System::Windows::Forms::Timer^ timer_applicatin;
		   BufferedGraphics^ buffer;
	public:
		MyForm(void)
		{
			InitializeComponent();
			graficador = CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(graficador, this->ClientRectangle);
			controller = gcnew Controller();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete buffer;
				delete graficador;
				delete controller;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer_applicatin = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer_applicatin
			// 
			this->timer_applicatin->Enabled = true;
			this->timer_applicatin->Tick += gcnew System::EventHandler(this, &MyForm::animar);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(538, 361);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		this->controller->detectarTeclas(e->KeyCode, this->buffer->Graphics);
	}
	private: System::Void animar(System::Object^ sender, System::EventArgs^ e) {
		this->buffer->Graphics->Clear(Color::White);
		this->controller->animar(this->buffer->Graphics);
		this->buffer->Render();
	}
	};
}
