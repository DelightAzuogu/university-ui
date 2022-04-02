#pragma once
#include <mysql.h>
#include <string>
#include <cstring>
#include "instructor.h"
#include "coordinator.h"
#include "studentPage.h"
#include <iostream>



namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;

	/// <summary>
	/// Summary for loginh
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
		
	public:
		int year;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ usernametext;
	private: System::Windows::Forms::TextBox^ passwordtext;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ studentcheck;
	private: System::Windows::Forms::CheckBox^ instructorcheck;
	private: System::Windows::Forms::CheckBox^ coordinatorcheck;
	private: System::Windows::Forms::Button^ loginbutton;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ checkerror;
	private: System::Windows::Forms::Label^ passworderror;
	private: System::Windows::Forms::Label^ usernameerror;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;

	public:
		String^ semester;

		login(int yearPara, String^ semesterPara)
		{	
			year = yearPara;
			semester = semesterPara;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent()
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(login::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->usernametext = (gcnew System::Windows::Forms::TextBox());
			this->passwordtext = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->studentcheck = (gcnew System::Windows::Forms::CheckBox());
			this->instructorcheck = (gcnew System::Windows::Forms::CheckBox());
			this->coordinatorcheck = (gcnew System::Windows::Forms::CheckBox());
			this->loginbutton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkerror = (gcnew System::Windows::Forms::Label());
			this->passworderror = (gcnew System::Windows::Forms::Label());
			this->usernameerror = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(23, 14);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 44);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(79, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(371, 42);
			this->label4->TabIndex = 14;
			this->label4->Text = L"LOGO UNIVERSITY";
			// 
			// usernametext
			// 
			this->usernametext->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernametext->Location = System::Drawing::Point(160, 19);
			this->usernametext->Name = L"usernametext";
			this->usernametext->Size = System::Drawing::Size(210, 20);
			this->usernametext->TabIndex = 2;
			// 
			// passwordtext
			// 
			this->passwordtext->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordtext->Location = System::Drawing::Point(160, 55);
			this->passwordtext->Name = L"passwordtext";
			this->passwordtext->Size = System::Drawing::Size(210, 20);
			this->passwordtext->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(86, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"usernane(ID)";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(86, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"password";
			// 
			// studentcheck
			// 
			this->studentcheck->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentcheck->AutoSize = true;
			this->studentcheck->Location = System::Drawing::Point(89, 104);
			this->studentcheck->Name = L"studentcheck";
			this->studentcheck->Size = System::Drawing::Size(61, 17);
			this->studentcheck->TabIndex = 6;
			this->studentcheck->Text = L"student";
			this->studentcheck->UseVisualStyleBackColor = true;
			this->studentcheck->Click += gcnew System::EventHandler(this, &login::studentcheck_Click);
			// 
			// instructorcheck
			// 
			this->instructorcheck->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->instructorcheck->AutoSize = true;
			this->instructorcheck->Location = System::Drawing::Point(191, 104);
			this->instructorcheck->Name = L"instructorcheck";
			this->instructorcheck->Size = System::Drawing::Size(69, 17);
			this->instructorcheck->TabIndex = 7;
			this->instructorcheck->Text = L"instructor";
			this->instructorcheck->UseVisualStyleBackColor = true;
			this->instructorcheck->Click += gcnew System::EventHandler(this, &login::instructorcheck_Click);
			// 
			// coordinatorcheck
			// 
			this->coordinatorcheck->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->coordinatorcheck->AutoSize = true;
			this->coordinatorcheck->Location = System::Drawing::Point(291, 104);
			this->coordinatorcheck->Name = L"coordinatorcheck";
			this->coordinatorcheck->Size = System::Drawing::Size(79, 17);
			this->coordinatorcheck->TabIndex = 8;
			this->coordinatorcheck->Text = L"coordinator";
			this->coordinatorcheck->UseVisualStyleBackColor = true;
			this->coordinatorcheck->Click += gcnew System::EventHandler(this, &login::coordinatorcheck_Click);
			// 
			// loginbutton
			// 
			this->loginbutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->loginbutton->BackColor = System::Drawing::Color::Teal;
			this->loginbutton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->loginbutton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginbutton->Location = System::Drawing::Point(89, 154);
			this->loginbutton->Name = L"loginbutton";
			this->loginbutton->Size = System::Drawing::Size(281, 48);
			this->loginbutton->TabIndex = 9;
			this->loginbutton->Text = L"LOGIN";
			this->loginbutton->UseVisualStyleBackColor = false;
			this->loginbutton->Click += gcnew System::EventHandler(this, &login::loginbutton_Click);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(385, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 10;
			// 
			// checkerror
			// 
			this->checkerror->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->checkerror->AutoSize = true;
			this->checkerror->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkerror->Location = System::Drawing::Point(385, 104);
			this->checkerror->Name = L"checkerror";
			this->checkerror->Size = System::Drawing::Size(13, 13);
			this->checkerror->TabIndex = 11;
			this->checkerror->Text = L"  ";
			// 
			// passworderror
			// 
			this->passworderror->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passworderror->AutoSize = true;
			this->passworderror->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passworderror->Location = System::Drawing::Point(376, 62);
			this->passworderror->Name = L"passworderror";
			this->passworderror->Size = System::Drawing::Size(13, 13);
			this->passworderror->TabIndex = 12;
			this->passworderror->Text = L"  ";
			// 
			// usernameerror
			// 
			this->usernameerror->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameerror->AutoSize = true;
			this->usernameerror->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameerror->Location = System::Drawing::Point(376, 22);
			this->usernameerror->Name = L"usernameerror";
			this->usernameerror->Size = System::Drawing::Size(13, 13);
			this->usernameerror->TabIndex = 13;
			this->usernameerror->Text = L"  ";
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->usernameerror);
			this->panel1->Controls->Add(this->passworderror);
			this->panel1->Controls->Add(this->checkerror);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->loginbutton);
			this->panel1->Controls->Add(this->coordinatorcheck);
			this->panel1->Controls->Add(this->instructorcheck);
			this->panel1->Controls->Add(this->studentcheck);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->passwordtext);
			this->panel1->Controls->Add(this->usernametext);
			this->panel1->Location = System::Drawing::Point(57, 112);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(480, 215);
			this->panel1->TabIndex = 15;
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->BackColor = System::Drawing::Color::CadetBlue;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Location = System::Drawing::Point(57, 41);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(480, 69);
			this->panel2->TabIndex = 14;
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(608, 357);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimumSize = System::Drawing::Size(624, 396);
			this->Name = L"login";
			this->Text = L"LOGIN";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void loginbutton_Click(System::Object^ sender, System::EventArgs^ e) {

	checkerror->Text = "  ";
	passworderror->Text = " ";
	usernameerror->Text = " ";
	//check if anything is inputted
	if (instructorcheck->Checked == false && studentcheck->Checked == false && coordinatorcheck->Checked == false) {
		checkerror->Text = "what are you signing in as";
	}
	if (passwordtext->Text == "") {
		passworderror->Text = "enter a password";
	}
	if (usernameerror->Text == "") {
		usernameerror->Text = "enter a username";
	}
	
	//if things are inputted
	if (instructorcheck->Checked == true || studentcheck->Checked == true || coordinatorcheck->Checked == true) {
		if (passwordtext->Text != "" && usernametext->Text != "") {
			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			MYSQL_RES* res;
			MYSQL_ROW row;

			if (con) {

				//instructor
				if (instructorcheck->Checked == true) {

					const char* username = (const char*)(Marshal::StringToHGlobalAnsi(usernametext->Text)).ToPointer();
					int chars_size = sizeof(username) / sizeof(char);

					std::string s(username);
					std::string query = "select password from instructor where id = " + s + " and status = true;";

					int check = mysql_query(con, query.c_str());

					if (!check) {
						res = mysql_store_result(con);
						if (mysql_num_rows(res) == 0) {
							usernameerror->Text = "invalid id";
						}

						else {
							const char* password = (const char*)(Marshal::StringToHGlobalAnsi(passwordtext->Text)).ToPointer();
							row = mysql_fetch_row(res);
							char * passwordCheck = row[0];

							if (!strcmp(row[0], password)) {
								this->Hide();
								instructor^ obj = gcnew instructor(this,s, year, semester);
								obj->ShowDialog();
							} 
							else{
								passworderror->Text = "invalid password";
							}
						}
						mysql_free_result(res);
					}
				}
				//end instructor

				//student
				if (studentcheck->Checked == true) {

					char* username = (char*)(Marshal::StringToHGlobalAnsi(usernametext->Text)).ToPointer();
					int chars_size = sizeof(username) / sizeof(char);

					std::string s(username);
					std::string query = "select password from student where id = " + s + " and status = true;";

					int check = mysql_query(con, query.c_str());

					if (!check) {
						res = mysql_store_result(con);
						if (mysql_num_rows(res) == 0) {
							usernameerror->Text = "invalid id";
						}

						else {
							const char* password = (const char*)(Marshal::StringToHGlobalAnsi(passwordtext->Text)).ToPointer();
							row = mysql_fetch_row(res);

							if (!strcmp(password,row[0])) {
								this->Hide();
								
								studentPage^ obj = gcnew studentPage(year, username, semester,this);
								obj->ShowDialog();
							}
							else {
								passworderror->Text = "invalid password";
							}
						}
						mysql_free_result(res);
					}
				}
				//end student
				//coordinator
				if (coordinatorcheck->Checked == true) {

					const char* username = (const char*)(Marshal::StringToHGlobalAnsi(usernametext->Text)).ToPointer();
					int chars_size = sizeof(username) / sizeof(char);

					std::string s(username);
					std::string query = "select password from coordinator where i_id = " + s + ";";

					int check = mysql_query(con, query.c_str());

					if (!check) {
						res = mysql_store_result(con);
						if (mysql_num_rows(res) == 0) {
							usernameerror->Text = "invalid id";
						}

						else {
							const char* password = (const char*)(Marshal::StringToHGlobalAnsi(passwordtext->Text)).ToPointer();
							row = mysql_fetch_row(res);

							if (!strcmp(password, row[0])) {
								this->Hide();
								coordinator^ obj = gcnew coordinator(this, s, year, semester);
								obj->ShowDialog();
							}
							else {
								passworderror->Text = "invalid password";
							}
						}
						mysql_free_result(res);
					}
				}
				//end coordinator
			}
		}
	}

}

private: System::Void coordinatorcheck_Click(System::Object^ sender, System::EventArgs^ e) {
	studentcheck->Checked = false;
	instructorcheck->Checked = false;
	coordinatorcheck->Checked = true;
}
private: System::Void instructorcheck_Click(System::Object^ sender, System::EventArgs^ e) {
	studentcheck->Checked = false;
	instructorcheck->Checked = true;
	coordinatorcheck->Checked = false;
}
private: System::Void studentcheck_Click(System::Object^ sender, System::EventArgs^ e) {
	studentcheck->Checked = true;
	instructorcheck->Checked = false;
	coordinatorcheck->Checked = false;
}
};
}
