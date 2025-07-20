#pragma once
#include "MyForm.h"
#include "MyForm2.h"
namespace Tfalphav05 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		SoundPlayer^ Mar = gcnew SoundPlayer("Sonido_Mar.wav");
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private:
		String^ nombre_del_jugador;
	private: System::Windows::Forms::Button^ button4;
		   /// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlText;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(125, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 120);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Nivel 1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlText;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(347, 71);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(190, 120);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Nivel 2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(125, 247);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(189, 111);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Creditos";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->Location = System::Drawing::Point(347, 247);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(190, 111);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Reglas";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(674, 500);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void Cambiar_nombre_jugador(String^ nuevo)
	{
		nombre_del_jugador = nuevo;
	}
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {

		Mar->PlayLooping();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Mar->Stop();
		Tfalphav05::MyForm^ nivel_1 = gcnew Tfalphav05::MyForm();
		nivel_1->Cambiar_nombre_jugador_nivel1(nombre_del_jugador);
		this->Visible = false;
		nivel_1->ShowDialog();
		nivel_1->Close();
		this->Visible = true;
		Mar->PlayLooping();

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		Mar->Stop();
		Tfalphav05::MyForm2^ nivel_2 = gcnew Tfalphav05::MyForm2();
		nivel_2->Cambiar_nombre_jugador_nivel2(nombre_del_jugador);
		this->Visible = false;
		nivel_2->ShowDialog();
		nivel_2->Close();
		this->Visible = true;
		Mar->PlayLooping();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		MessageBox::Show("Integrantes:" + "\n Fabrizio Valderrama\n Maria Fernanda Falcón\n Rodrigo Marcos\n Enzo Gonzales");
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	MessageBox::Show("Reglas generales:\n\nEl buceador se moverá con las teclas direccionales o AWSD.\nEl buceador cuenta con 3 vidas.\nPara disparar las flechas se usa la tecla espacio.\nCada 30 basuritas recogidas el buceador recibirá una vida más.\nExistirán 10 bonuses esparcidos por todo el mapa, los cuales potenciarán durante 4 segundos la velocidad de desplazamiento al doble.\nEl buceador contará con 5 flechas.\nHabrá 5 arpones esparcidos por el mapa(esta será la munición extra del buceador).\nCuando una flecha choque con el enemigo, éste perderá una vida.\nLos animales y el buceador no podrán salir a la superficie.\nCuando el buceador solo tenga una flecha disponible en el cargador, aparecerá de forma periódica un pájaro que al dispararle dará un bonus de 20 flechas(solo se habilitará el bonus una vez por partida).\n\nPrimer nivel :\nEl primer nivel durará 3 minutos.\nEl buceador será perseguido por 6 pirañas hambrientas.\nLas pirañas tendrán entre 1 a 3 vidas.\nSi una piraña pierde todas sus vidas desaparecerá.\nEl buceador pierde una vida cuando choca con las pirañas.\nEl buceador vuelve a la posición inicial cuando pierde una vida.\nEl buceador debe recolectar 100 basuritas para completar el nivel.\n\nSegundo nivel :\nEl segundo nivel durará 2 minutos.\nEl buceador será perseguido por 8 tiburones asesinos.\nLos tiburones tendrán entre 2 a 4 vidas.\nSi un tiburón pierde todas sus vidas desaparecerá.\nEl buceador pierde una vida cuando choca con los tiburones.\nEl buceador vuelve a la posición inicial cuando pierde una vida.\nEl buceador debe recolectar 150 basuritas para completar el nivel.");
}
};
}
