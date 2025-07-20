#pragma once
#include "Controladora.h"
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
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		SoundPlayer^ Soundtrack = gcnew SoundPlayer("Yellow_SubmarineHQ.wav"); 
		MyForm(void)
		{
			InitializeComponent();
			objcontroladora = new Controladora();
			bmpBasura = gcnew Bitmap("Basura.png");
			bmpBonus = gcnew Bitmap("Estrella.png");
			bmpBuzo = gcnew Bitmap("Buzo.png");
			bmpFondo = gcnew Bitmap("Fondo.png");
			bmpPiraña = gcnew Bitmap("Piraña.png");
			bmpTiburon = gcnew Bitmap("Tiburon.png");
			bmpFlechas = gcnew Bitmap("Flechas.png");
			bmpArpon = gcnew Bitmap("Arpon.png");
			bmpLoading = gcnew Bitmap("Cargando.png");
			bmpPajaro = gcnew Bitmap("pajaro.png");

			//
			//TODO: agregar código de constructor aquí
			//
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
			delete objcontroladora, bmpBasura, bmpBonus, bmpBuzo, bmpFondo, bmpPiraña, bmpTiburon, bmpArpon, bmpFlechas, bmpLoading, bmpPajaro;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Controladora* objcontroladora;
		Bitmap^ bmpPiraña;
		Bitmap^ bmpTiburon;
		Bitmap^ bmpFondo;
		Bitmap^ bmpBuzo;
		Bitmap^ bmpBasura;
		Bitmap^ bmpBonus;
		Bitmap^ bmpArpon;
		Bitmap^ bmpLoading;
		Bitmap^ bmpPajaro;
		String^ nombre_del_jugador_nivel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Timer^ timer2;
		   Bitmap^ bmpFlechas;

		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(61, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(0, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Tiempo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(61, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(203, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 17);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Munición:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(277, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(136, 36);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(135, 17);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Basura recolectada:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(277, 36);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(46, 17);
			this->label8->TabIndex = 7;
			this->label8->Text = L"label8";
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1075, 494);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void Cambiar_nombre_jugador_nivel1(String^ nuevo)
	{
		nombre_del_jugador_nivel1 = nuevo;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

		objcontroladora->Parametros_nivel();

		bf->Graphics->Clear(Color::White);
		bf->Graphics->DrawImage(bmpFondo, 0, 0, (int)bf->Graphics->VisibleClipBounds.Width, (int)bf->Graphics->VisibleClipBounds.Height);
		label2->Text = objcontroladora->retornar_vidas() + "";
		label4->Text = ((clock() - objcontroladora->Retornar_inicio()) / CLOCKS_PER_SEC) + "";
		label6->Text = objcontroladora->retornar_municion() + "";
		label8->Text = objcontroladora->retornar_contador_de_basura() + "";
		objcontroladora->Generar_Pajaros();
		objcontroladora->Dibujar_Pajaros(bf->Graphics, bmpPajaro);
		objcontroladora->Dibujar_Basuras(bf->Graphics, bmpBasura);
		objcontroladora->Dibujar_Bonus(bf->Graphics, bmpBonus);
		objcontroladora->Dibujar_Arpones(bf->Graphics, bmpArpon);
		objcontroladora->Dibujar_Pirañas(bf->Graphics, bmpPiraña);
		objcontroladora->Dibujar_Buceador(bf->Graphics, bmpBuzo);
		objcontroladora->Dibujar_Balas(bf->Graphics, bmpFlechas);

		bf->Render(g);
		if (objcontroladora->retornar_nivel() == 2)
		{
			vector<string> datos;
			char auxiliar[100];
			sprintf(auxiliar, "%s", nombre_del_jugador_nivel1);
			datos.push_back(auxiliar);
			datos.push_back(std::to_string(objcontroladora->retornar_puntaje())); // convierte de int a string
			objcontroladora->GrabarenArchivo(datos);

			Soundtrack->Stop();
			timer1->Enabled = false;
			MessageBox::Show("Felicidades!" + "    Cargando nivel 2...\n\nEl puntaje obtenido fue:  " + objcontroladora->retornar_puntaje());
			//Close();
			Tfalphav05::MyForm2^ nivel_2 = gcnew Tfalphav05::MyForm2();
			nivel_2->Cambiar_nombre_jugador_nivel2(nombre_del_jugador_nivel1);
			this->Visible = false;
			nivel_2->ShowDialog();
		}

		else if (objcontroladora->retornar_cerrar() == true)
		{	
			vector<string> datos;
			char auxiliar[100];
			sprintf(auxiliar, "%s", nombre_del_jugador_nivel1);
			datos.push_back(auxiliar);
			datos.push_back(std::to_string(objcontroladora->retornar_puntaje())); // convierte de int a string
			objcontroladora->GrabarenArchivo(datos);

			Soundtrack->Stop();
			timer1->Enabled = false;
			if (objcontroladora->retornar_vidas() == 0)
			{
				MessageBox::Show("Perdiste :( \nTe quedaste sin vidas\n\nEl puntaje obtenido fue:  " + objcontroladora->retornar_puntaje());
			}
			else
			{
				MessageBox::Show("Perdiste :( \nSe agotó el tiempo\n\nEl puntaje obtenido fue:  " + objcontroladora->retornar_puntaje());
			}
			this->Visible = false;

			//delete bf, espacio, g;
			//timer1->Enabled = false;
		}

		delete bf, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		
		if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left)
		{
			objcontroladora->Desplazar_Buceador(direccion::izquierda);
		}
		if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) objcontroladora->Desplazar_Buceador(direccion::derecha);
		if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) objcontroladora->Desplazar_Buceador(direccion::arriba);
		if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) objcontroladora->Desplazar_Buceador(direccion::abajo);
		if (e->KeyCode == Keys::Space) objcontroladora->Disparar();
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {

	Graphics^ g = CreateGraphics();
	BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
	BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

	bf->Graphics->Clear(Color::White);

	objcontroladora->Dibujar_Loading(bf->Graphics, bmpLoading);
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	Soundtrack->PlayLooping();
}
};
}
