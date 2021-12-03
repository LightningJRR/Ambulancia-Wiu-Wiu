#pragma once
#include "Controller.h"
#include "Data.h"
namespace ambulancia {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmaps
			bmpAmb = gcnew Bitmap("ambu.png");
			bmpPca = gcnew Bitmap("caminando.png");
			bmpPco = gcnew Bitmap("corriendo.png");
			/*bmpPared = gcnew Bitmap("lagrima.png");
			bmpPlanta = gcnew Bitmap("plantas.png");
			bmpStar = gcnew Bitmap("star.png");
			bmpFondo = gcnew Bitmap("fondo.png");*/


			//Controller
			controller = new Controller(bmpAmb, bmpPca, bmpPco);

			//file 
			file = new Datos();

			timer2->Interval = file->getS() * 1000;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpAmb;
		Bitmap^ bmpPco;
		Bitmap^ bmpPca;
		Bitmap^ bmpStar;
		Bitmap^ bmpFondo;

		//Controller
		Controller* controller;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer3;

		Datos* file;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(757, 531);
			this->panel1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(663, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 0;
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Interval = 1000;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(758, 533);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);

		controller->colision();
		controller->movertodo(buffer->Graphics);
		controller->dibujartodo(buffer->Graphics, bmpAmb, bmpPca, bmpPco);


		if (file->getT() == 0) {
			timer1->Enabled = false;
			timer2->Enabled = false;
			MessageBox::Show("Total de puntos obtenidos: " + controller->getcontP());
			this->Close();
		}
		else {
			label1->Text = Convert::ToString("Puntos: " + controller->getcontP());
			label2->Text = Convert::ToString("Tiempo: " + file->getT());
			buffer->Render(g);
		}
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			controller->getambu()->move(buffer->Graphics, 'A'); break;
		case Keys::D: case Keys::Right:
			controller->getambu()->move(buffer->Graphics, 'D'); break;
		case Keys::W: case Keys::Up:
			controller->getambu()->move(buffer->Graphics, 'W'); break;
		case Keys::S: case Keys::Down:
			controller->getambu()->move(buffer->Graphics, 'S'); break;
		}
	}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	controller->agregarPca(bmpPca);
	controller->agregarPco(bmpPco);
}
private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
	file->setT(file->getT() - 1);
}
};
}
