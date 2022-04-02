#pragma once
#include <mysql.h>
#include <string>
#include <cctype>
#include <cstring>
#include <iostream>
#include "CordAddInstructor.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing;
	using namespace std;
	string facultyNamE;
	string Semester;
	/// <summary>
	/// Summary for cordInstructor
	/// </summary>
	public ref class cordInstructor : public System::Windows::Forms::Form
	{
		int year;
	private: System::Windows::Forms::Label^ idError;

	private: System::Windows::Forms::TextBox^ instructorId;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ courseError;
	private: System::Windows::Forms::TextBox^ courseCode;




	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ groupError;

	private: System::Windows::Forms::TextBox^ groupNo;


	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ buildingError;



	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ roomError;



	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ timeId;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ stmt;
	private: System::Windows::Forms::Label^ timeError;
	private: System::Windows::Forms::ComboBox^ buildingBox;
	private: System::Windows::Forms::ComboBox^ roomBox;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label3;








		   MYSQL* con;
	public:
		cordInstructor(string facultyNamePara, int yearPara, string semesterPara)
		{
			facultyNamE = facultyNamePara;
			year = yearPara;
			Semester = semesterPara;
			con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			string query = "select * from time_slot;";

			int check = mysql_query(con, query.c_str());

			MYSQL_RES* res;
			MYSQL_ROW row;
			if (!check) {
				res = mysql_store_result(con);
				while ((row = mysql_fetch_row(res)) != NULL) {
					string id(row[0]);
					string day(row[1]);
					string startT(row[2]);
					string endT(row[3]);
					string time_slot = id + "--" + day + "--" + startT + "--" + endT;
					timeId->Items->Add(gcnew String(time_slot.c_str()));
				}
			}

			query = "select distinct(building) from classroom;";
			check = mysql_query(con, query.c_str());


			if (!check) {
				res = mysql_store_result(con);
				while ((row = mysql_fetch_row(res)) != NULL) {
					buildingBox->Items->Add(gcnew String(row[0]));
				}
			}
			mysql_free_result(res);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~cordInstructor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ addInstructorbutton;
	private: System::Windows::Forms::TextBox^ InstructorNo;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ StudentNo;



	private: System::Windows::Forms::Label^ label2;



	private: System::Windows::Forms::Button^ assignAdvisorButton;




	private: System::Windows::Forms::Label^ iIDError;
	private: System::Windows::Forms::Label^ stIdError;


	private: System::Windows::Forms::Label^ assignStmt;






	protected:









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(cordInstructor::typeid));
			this->addInstructorbutton = (gcnew System::Windows::Forms::Button());
			this->InstructorNo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->StudentNo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->assignAdvisorButton = (gcnew System::Windows::Forms::Button());
			this->iIDError = (gcnew System::Windows::Forms::Label());
			this->stIdError = (gcnew System::Windows::Forms::Label());
			this->assignStmt = (gcnew System::Windows::Forms::Label());
			this->idError = (gcnew System::Windows::Forms::Label());
			this->instructorId = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->courseError = (gcnew System::Windows::Forms::Label());
			this->courseCode = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupError = (gcnew System::Windows::Forms::Label());
			this->groupNo = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->buildingError = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->roomError = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timeId = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->stmt = (gcnew System::Windows::Forms::Label());
			this->timeError = (gcnew System::Windows::Forms::Label());
			this->buildingBox = (gcnew System::Windows::Forms::ComboBox());
			this->roomBox = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// addInstructorbutton
			// 
			this->addInstructorbutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addInstructorbutton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addInstructorbutton->Location = System::Drawing::Point(40, 154);
			this->addInstructorbutton->Name = L"addInstructorbutton";
			this->addInstructorbutton->Size = System::Drawing::Size(291, 48);
			this->addInstructorbutton->TabIndex = 9;
			this->addInstructorbutton->Text = L"Add Instructor";
			this->addInstructorbutton->UseVisualStyleBackColor = true;
			this->addInstructorbutton->Click += gcnew System::EventHandler(this, &cordInstructor::addInstructorbutton_Click);
			// 
			// InstructorNo
			// 
			this->InstructorNo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InstructorNo->Location = System::Drawing::Point(95, 286);
			this->InstructorNo->MaxLength = 10;
			this->InstructorNo->Name = L"InstructorNo";
			this->InstructorNo->Size = System::Drawing::Size(209, 20);
			this->InstructorNo->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 288);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 15);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Instructor ID";
			// 
			// StudentNo
			// 
			this->StudentNo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StudentNo->Location = System::Drawing::Point(95, 325);
			this->StudentNo->MaxLength = 10;
			this->StudentNo->Name = L"StudentNo";
			this->StudentNo->Size = System::Drawing::Size(209, 20);
			this->StudentNo->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(10, 327);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 15);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Student ID";
			// 
			// assignAdvisorButton
			// 
			this->assignAdvisorButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->assignAdvisorButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->assignAdvisorButton->Location = System::Drawing::Point(40, 397);
			this->assignAdvisorButton->Name = L"assignAdvisorButton";
			this->assignAdvisorButton->Size = System::Drawing::Size(291, 48);
			this->assignAdvisorButton->TabIndex = 14;
			this->assignAdvisorButton->Text = L"Assign Advisor";
			this->assignAdvisorButton->UseVisualStyleBackColor = true;
			this->assignAdvisorButton->Click += gcnew System::EventHandler(this, &cordInstructor::assignAdvisorButton_Click);
			// 
			// iIDError
			// 
			this->iIDError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->iIDError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->iIDError->Location = System::Drawing::Point(310, 288);
			this->iIDError->Name = L"iIDError";
			this->iIDError->Size = System::Drawing::Size(68, 18);
			this->iIDError->TabIndex = 16;
			this->iIDError->Text = L"       ";
			// 
			// stIdError
			// 
			this->stIdError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->stIdError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stIdError->Location = System::Drawing::Point(310, 327);
			this->stIdError->Name = L"stIdError";
			this->stIdError->Size = System::Drawing::Size(68, 18);
			this->stIdError->TabIndex = 17;
			this->stIdError->Text = L"       ";
			// 
			// assignStmt
			// 
			this->assignStmt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->assignStmt->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->assignStmt->Location = System::Drawing::Point(13, 361);
			this->assignStmt->Name = L"assignStmt";
			this->assignStmt->Size = System::Drawing::Size(291, 18);
			this->assignStmt->TabIndex = 19;
			this->assignStmt->Text = L"       ";
			// 
			// idError
			// 
			this->idError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->idError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idError->Location = System::Drawing::Point(705, 73);
			this->idError->Name = L"idError";
			this->idError->Size = System::Drawing::Size(123, 18);
			this->idError->TabIndex = 22;
			this->idError->Text = L"       ";
			// 
			// instructorId
			// 
			this->instructorId->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->instructorId->Location = System::Drawing::Point(490, 71);
			this->instructorId->MaxLength = 10;
			this->instructorId->Name = L"instructorId";
			this->instructorId->Size = System::Drawing::Size(209, 20);
			this->instructorId->TabIndex = 20;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(405, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 15);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Instructor ID";
			// 
			// courseError
			// 
			this->courseError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->courseError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->courseError->Location = System::Drawing::Point(705, 114);
			this->courseError->Name = L"courseError";
			this->courseError->Size = System::Drawing::Size(123, 18);
			this->courseError->TabIndex = 25;
			this->courseError->Text = L"       ";
			// 
			// courseCode
			// 
			this->courseCode->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->courseCode->Location = System::Drawing::Point(490, 112);
			this->courseCode->MaxLength = 10;
			this->courseCode->Name = L"courseCode";
			this->courseCode->Size = System::Drawing::Size(209, 20);
			this->courseCode->TabIndex = 23;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(405, 114);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 15);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Course ID";
			// 
			// groupError
			// 
			this->groupError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupError->Location = System::Drawing::Point(705, 156);
			this->groupError->Name = L"groupError";
			this->groupError->Size = System::Drawing::Size(123, 18);
			this->groupError->TabIndex = 28;
			this->groupError->Text = L"       ";
			// 
			// groupNo
			// 
			this->groupNo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupNo->Location = System::Drawing::Point(490, 154);
			this->groupNo->MaxLength = 10;
			this->groupNo->Name = L"groupNo";
			this->groupNo->Size = System::Drawing::Size(209, 20);
			this->groupNo->TabIndex = 26;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(405, 156);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(88, 15);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Group Number";
			// 
			// buildingError
			// 
			this->buildingError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buildingError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buildingError->Location = System::Drawing::Point(705, 200);
			this->buildingError->Name = L"buildingError";
			this->buildingError->Size = System::Drawing::Size(123, 18);
			this->buildingError->TabIndex = 31;
			this->buildingError->Text = L"       ";
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(405, 200);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(55, 15);
			this->label11->TabIndex = 30;
			this->label11->Text = L"Building";
			// 
			// roomError
			// 
			this->roomError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->roomError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->roomError->Location = System::Drawing::Point(705, 244);
			this->roomError->Name = L"roomError";
			this->roomError->Size = System::Drawing::Size(123, 18);
			this->roomError->TabIndex = 34;
			this->roomError->Text = L"       ";
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(405, 244);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(85, 15);
			this->label13->TabIndex = 33;
			this->label13->Text = L"Room Number";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(433, 287);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 15);
			this->label5->TabIndex = 39;
			this->label5->Text = L"Time";
			// 
			// timeId
			// 
			this->timeId->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->timeId->FormattingEnabled = true;
			this->timeId->Location = System::Drawing::Point(490, 285);
			this->timeId->Name = L"timeId";
			this->timeId->Size = System::Drawing::Size(208, 21);
			this->timeId->TabIndex = 40;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(408, 408);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(291, 48);
			this->button1->TabIndex = 41;
			this->button1->Text = L"Replace Instructor";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &cordInstructor::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(408, 343);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(291, 48);
			this->button2->TabIndex = 42;
			this->button2->Text = L"Assign instructor";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &cordInstructor::button2_Click);
			// 
			// stmt
			// 
			this->stmt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->stmt->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stmt->Location = System::Drawing::Point(705, 387);
			this->stmt->Name = L"stmt";
			this->stmt->Size = System::Drawing::Size(123, 18);
			this->stmt->TabIndex = 43;
			this->stmt->Text = L"       ";
			// 
			// timeError
			// 
			this->timeError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->timeError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeError->Location = System::Drawing::Point(705, 288);
			this->timeError->Name = L"timeError";
			this->timeError->Size = System::Drawing::Size(123, 18);
			this->timeError->TabIndex = 44;
			this->timeError->Text = L"       ";
			// 
			// buildingBox
			// 
			this->buildingBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buildingBox->FormattingEnabled = true;
			this->buildingBox->Location = System::Drawing::Point(490, 198);
			this->buildingBox->Name = L"buildingBox";
			this->buildingBox->Size = System::Drawing::Size(208, 21);
			this->buildingBox->TabIndex = 45;
			this->buildingBox->SelectedIndexChanged += gcnew System::EventHandler(this, &cordInstructor::buildingBox_SelectedIndexChanged);
			// 
			// roomBox
			// 
			this->roomBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->roomBox->FormattingEnabled = true;
			this->roomBox->Location = System::Drawing::Point(490, 242);
			this->roomBox->Name = L"roomBox";
			this->roomBox->Size = System::Drawing::Size(208, 21);
			this->roomBox->TabIndex = 46;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(16, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 44);
			this->pictureBox2->TabIndex = 47;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(72, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(388, 44);
			this->label3->TabIndex = 48;
			this->label3->Text = L"LOGO UNIVERISITY";
			// 
			// cordInstructor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(848, 468);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->roomBox);
			this->Controls->Add(this->buildingBox);
			this->Controls->Add(this->timeError);
			this->Controls->Add(this->stmt);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->timeId);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->roomError);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->buildingError);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->groupError);
			this->Controls->Add(this->groupNo);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->courseError);
			this->Controls->Add(this->courseCode);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->idError);
			this->Controls->Add(this->instructorId);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->assignStmt);
			this->Controls->Add(this->stIdError);
			this->Controls->Add(this->iIDError);
			this->Controls->Add(this->assignAdvisorButton);
			this->Controls->Add(this->StudentNo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->addInstructorbutton);
			this->Controls->Add(this->InstructorNo);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"cordInstructor";
			this->Text = L"Instructor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void assignAdvisorButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string intId((char*)(Marshal::StringToHGlobalAnsi(InstructorNo->Text)).ToPointer());
		string stuId((char*)(Marshal::StringToHGlobalAnsi(StudentNo->Text)).ToPointer());

		if (intId == "") {
			iIDError->Text = "!!!";
		}
		if (stuId == "") {
			stIdError->Text = "!!!";
		}

		if (intId != "" && stuId != "") {
			string query = "select * from advisor where s_id = " + stuId + ";";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				MYSQL_RES* res = mysql_store_result(con);
				int count = mysql_num_rows(res);
				if (count > 0) { // update
					query = "update advisor set i_id = " + intId + " where s_id = " + stuId + ";";
					check = mysql_query(con, query.c_str());
					if (!check) {
						assignStmt->Text = "updated";
					}
					else
						assignStmt->Text = "!!!";
				}
				else { // insert
					query = "insert into advisor values(" + stuId + "," + intId + ");";
					check = mysql_query(con, query.c_str());
					if (!check) {
						assignStmt->Text = "added";
					}
					else
						assignStmt->Text = "!!!";
				}
			}
		}
	}
	private: System::Void addInstructorbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		CordAddInstructor^ obj = gcnew CordAddInstructor(facultyNamE);
		obj->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		string intId((char*)(Marshal::StringToHGlobalAnsi(instructorId->Text)).ToPointer());
		string code((char*)(Marshal::StringToHGlobalAnsi(courseCode->Text)).ToPointer());
		string group((char*)(Marshal::StringToHGlobalAnsi(groupNo->Text)).ToPointer());
		string building((char*)(Marshal::StringToHGlobalAnsi(buildingBox->Text)).ToPointer());
		string room((char*)(Marshal::StringToHGlobalAnsi(roomBox->Text)).ToPointer());
		string timeslot = to_string((timeId->SelectedIndex) + 1);

		if (intId == "") {
			idError->Text = "!!!";
		}
		if (code == "") {
			courseError->Text = "!!!";
		}
		if (group == "") {
			groupError->Text = "!!!";
		}
		if (building == "") {
			buildingError->Text = "!!!";
		}
		if (room == "") {
			roomError->Text = "!!!";
		}
		if (timeslot == "") {
			timeError->Text = "!!!";
		}

		if (intId != "" && code != "" && group != "" && building != "" && room != "" && timeslot != "") {
			string query = "select * from instructor where id = " + intId + " and status = true;";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				MYSQL_RES* res = mysql_store_result(con);
				int count = mysql_num_rows(res);
				if (count > 0) {

					query = "select * from teaches where i_id = " + intId + " and semester = \"" + Semester + "\" and year = " + to_string(year) + ";";
					check = mysql_query(con, query.c_str());
					if (!check) {
						res = mysql_store_result(con);
						count = mysql_num_rows(res);
						if (count < 6) {

							query = "insert into section values (\"" + code + "\"," + group + ", \"" + Semester + "\","
								+ to_string(year) + ", \"" + building + "\"," + room + "," + timeslot + ");";
							check = mysql_query(con, query.c_str());
							if (!check) {
								query = "insert into teaches values (" + intId + ", \"" + code + "\", " + group + ", \"" + Semester + "\"," + to_string(year) + ");";
								check = mysql_query(con, query.c_str());
								if (!check) {
									stmt->Text = "success";
									roomBox->Text = "";
									roomBox->Items->Clear();
									timeId->Text = "";
									buildingBox->Text = "";
									groupNo->Text = "";
									courseCode->Text = "";
									instructorId->Text = "";
								}
							}
							else {
								stmt->Text = "course exists";
							}
						}
						else {
							stmt->Text = "limit reached";
						}

					}
				}
				else {
					idError->Text = "invalid";
				}
			}
		}



	}
	private: System::Void buildingBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		roomBox->Items->Clear();
		string building((char*)(Marshal::StringToHGlobalAnsi(buildingBox->Text)).ToPointer());

		string query = "select room_number from classroom where building = \"" + building + "\";";
		int check = mysql_query(con, query.c_str());

		MYSQL_RES* res;
		MYSQL_ROW row;
		if (!check) {
			res = mysql_store_result(con);
			while ((row = mysql_fetch_row(res)) != NULL) {
				roomBox->Items->Add(gcnew String(row[0]));
			}
		}
		mysql_free_result(res);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string intId((char*)(Marshal::StringToHGlobalAnsi(instructorId->Text)).ToPointer());
		string code((char*)(Marshal::StringToHGlobalAnsi(courseCode->Text)).ToPointer());
		string group((char*)(Marshal::StringToHGlobalAnsi(groupNo->Text)).ToPointer());

		if (intId == "") {
			idError->Text = "!!!";
		}
		if (code == "") {
			courseError->Text = "!!!";
		}
		if (group == "") {
			groupError->Text = "!!!";
		}

		if (intId != "" && code != "" && group != "") {
			string query = "update teaches set i_id = " + intId + " where semester = \"" + Semester + "\" and year = " + to_string(year) + " and course_code = \"" + code + "\" and group_number = " + group + ";";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				stmt->Text = "updated";
			}
			else {
				stmt->Text = "failed";
			}
		}
	}
	};
}
