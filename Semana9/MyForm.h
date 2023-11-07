#pragma once
#include "src/controllers/Controller.hpp"

namespace Semana9 {

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
		BufferedGraphics^ buffer;
		int messageBoxCount;
	public:
		MyForm(void)
		{
			InitializeComponent();
			graficador = CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(graficador, this->ClientRectangle);
			controller = gcnew Controller();
			messageBoxCount = 0;
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
				delete controller;
				delete buffer;
				delete graficador;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::animar);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(612, 429);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::presionarTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void animar(System::Object^ sender, System::EventArgs^ e) {
		this->buffer->Graphics->Clear(Color::White);
		bool animacionTerminada = this->controller->animar(this->buffer->Graphics);
		this->buffer->Render();
		if (animacionTerminada) {
			if (messageBoxCount == 0) {
				MessageBox::Show("Cantidad Circulos" + controller->getCantidadCirculos() + "\n"
					+ "Cantidad Triangulos: " + controller->getCantidadTriangulos());
				ShowDialog();
				++messageBoxCount;
				
			}
		}
	}
	private: System::Void presionarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		this->controller->detectarTeclas(this->buffer->Graphics, e->KeyCode);
	}
	};
}
