#pragma once
#include "login.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>


namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for student
	/// </summary>
	public ref class student : public System::Windows::Forms::Form
	{
	public:
		Form ^obj;
		student(Form^ obj_parameter, const char* id, int year, string semester)
		{
			obj = obj_parameter;
			InitializeComponent(id,year,semester);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~student()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ changePasswordToolStripMenuItem;
	private: System::Windows::Forms::Button^ course1;
	private: System::Windows::Forms::Button^ course2;
	private: System::Windows::Forms::Button^ course3;
	private: System::Windows::Forms::Button^ course4;
	private: System::Windows::Forms::Button^ course5;
	private: System::Windows::Forms::Button^ course6;






	private: System::Windows::Forms::GroupBox^ groupbox;
	private: System::Windows::Forms::Label^ namelabel;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ deptName;
	private: System::Windows::Forms::Label^ birthday;



	private: System::Windows::Forms::Label^ email;
	private: System::Windows::Forms::Button^ timetable;
	private: System::Windows::Forms::Button^ updateDetails;





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
		void InitializeComponent(const char *id)
		{
			//year
			//
			//
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->logoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changePasswordToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->course1 = (gcnew System::Windows::Forms::Button());
			this->course2 = (gcnew System::Windows::Forms::Button());
			this->course3 = (gcnew System::Windows::Forms::Button());
			this->course4 = (gcnew System::Windows::Forms::Button());
			this->course5 = (gcnew System::Windows::Forms::Button());
			this->course6 = (gcnew System::Windows::Forms::Button());
			this->groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->namelabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->deptName = (gcnew System::Windows::Forms::Label());
			this->birthday = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::Label());
			this->timetable = (gcnew System::Windows::Forms::Button());
			this->updateDetails = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupbox->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->logoutToolStripMenuItem,
					this->changePasswordToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->menuStrip1->Size = System::Drawing::Size(1200, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// logoutToolStripMenuItem
			// 
			this->logoutToolStripMenuItem->BackColor = System::Drawing::Color::IndianRed;
			this->logoutToolStripMenuItem->Name = L"logoutToolStripMenuItem";
			this->logoutToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->logoutToolStripMenuItem->Text = L"logout";
			// 
			// changePasswordToolStripMenuItem
			// 
			this->changePasswordToolStripMenuItem->BackColor = System::Drawing::Color::LightCyan;
			this->changePasswordToolStripMenuItem->Name = L"changePasswordToolStripMenuItem";
			this->changePasswordToolStripMenuItem->Size = System::Drawing::Size(111, 20);
			this->changePasswordToolStripMenuItem->Text = L"change password";
			// 
			// course1
			// 
			this->course1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			if (count >= 1) {
				this->course1->Location = System::Drawing::Point(26, 26);
				//roww = mysql_fetch_row(ress);
				//char* course_code = roww[0];
				this->course1->Text = gcnew String(course_code[1]);
			}
			else {
				this->course1->Location = System::Drawing::Point(5000, 5000);
				this->course1->Text = L"button1";
			}
			this->course1->Name = L"course1";
			this->course1->Size = System::Drawing::Size(159, 90);
			this->course1->TabIndex = 1;
			this->course1->UseVisualStyleBackColor = true;
			// 
			// course2
			// 
			this->course2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			if (count >= 2) {
				this->course2->Location = System::Drawing::Point(212, 26);
				//roww = mysql_fetch_row(ress);
				//char* course_code = roww[0];
				this->course2->Text = gcnew String(course_code[2]);
			}
			else {
				this->course2->Location = System::Drawing::Point(5000, 5000);
				this->course2->Text = L"button2";
			}
			this->course2->Name = L"course2";
			this->course2->Size = System::Drawing::Size(159, 90);
			this->course2->TabIndex = 2;
			
			this->course2->UseVisualStyleBackColor = true;
			// 
			// course3
			// 
			this->course3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			if (count >= 3) {
				this->course3->Location = System::Drawing::Point(410, 26);
				//roww = mysql_fetch_row(ress);
				//char* course_code = roww[0];
				this->course3->Text = gcnew String(course_code[3]);
			}
			else {
				this->course3->Location = System::Drawing::Point(5100, 5000);
				this->course3->Text = L"button3";
			}
			this->course3->Name = L"course3";
			this->course3->Size = System::Drawing::Size(159, 90);
			this->course3->TabIndex = 3;
			this->course3->UseVisualStyleBackColor = true;
			// 
			// course4
			// 
			
			this->course4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			if (count >= 4) {
				this->course4->Location = System::Drawing::Point(26, 161);
				//roww = mysql_fetch_row(ress);
				//char* course_code = roww[0];
				this->course4->Text = gcnew String(course_code[4]);
			}
			else {
				this->course4->Location = System::Drawing::Point(5526, 5161);
				this->course4->Text = L"button4";
			}
			this->course4->Name = L"course4";
			this->course4->Size = System::Drawing::Size(159, 90);
			this->course4->TabIndex = 4;
			
			this->course4->UseVisualStyleBackColor = true;
			// 
			// course5
			// 
			
			this->course5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			if (count >= 5) {

				//roww = mysql_fetch_row(ress);
				this->course5->Location = System::Drawing::Point(212, 161);
				//char* course_code = roww[0];

				this->course5->Text = gcnew String(course_code[5]);
			}
			else {
				this->course5->Location = System::Drawing::Point(5212, 5161);
				this->course5->Text = L"button5";
			}
			this->course5->Name = L"course5";
			this->course5->Size = System::Drawing::Size(159, 90);
			this->course5->TabIndex = 5;
			
			this->course5->UseVisualStyleBackColor = true;
			// 
			// course6
			// 
			this->course6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			if (count >= 6) {
				this->course6->Location = System::Drawing::Point(410, 161);
				//roww = mysql_fetch_row(ress);
				//char* course_code = roww[0];
				this->course6->Text = gcnew String(course_code[6]);
			}
			else {
				this->course6->Location = System::Drawing::Point(4100,5000);
				this->course6->Text = L"button6";
			}
			this->course6->Name = L"course6";
			this->course6->Size = System::Drawing::Size(159, 90);
			this->course6->TabIndex = 6;
			this->course6->Text = L"button6";
			this->course6->UseVisualStyleBackColor = true;
			// 
			// groupbox
			// 
			this->groupbox->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->groupbox->Controls->Add(this->course6);
			this->groupbox->Controls->Add(this->course5);
			this->groupbox->Controls->Add(this->course4);
			this->groupbox->Controls->Add(this->course3);
			this->groupbox->Controls->Add(this->course2);
			this->groupbox->Controls->Add(this->course1);
			this->groupbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupbox->Location = System::Drawing::Point(12, 122);
			this->groupbox->Name = L"groupbox";
			this->groupbox->Size = System::Drawing::Size(605, 275);
			this->groupbox->TabIndex = 7;
			this->groupbox->TabStop = false;
			this->groupbox->Text = L"COURSES";
			// 
			// namelabel
			// 
			this->namelabel->AutoSize = true;
			this->namelabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->namelabel->Location = System::Drawing::Point(700, 148);
			this->namelabel->Name = L"namelabel";
			this->namelabel->Size = System::Drawing::Size(45, 19);
			this->namelabel->TabIndex = 8;
			this->namelabel->Text = gcnew String(name);
			//
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(700, 202);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 19);
			this->label2->TabIndex = 9;
			this->label2->Text = gcnew String (id) ;
			// 
			// deptName
			// 
			this->deptName->AutoSize = true;
			this->deptName->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deptName->Location = System::Drawing::Point(700, 259);
			this->deptName->Name = L"deptName";
			this->deptName->Size = System::Drawing::Size(82, 19);
			this->deptName->TabIndex = 10;
			this->deptName->Text = gcnew String (row2[2]);
			// 
			// birthday
			// 
			this->birthday->AutoSize = true;
			this->birthday->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->birthday->Location = System::Drawing::Point(700, 358);
			this->birthday->Name = L"birthday";
			this->birthday->Size = System::Drawing::Size(37, 19);
			this->birthday->TabIndex = 11;
			this->birthday->Text = L"       ";
			// 
			// email
			// 
			this->email->AutoSize = true;
			this->email->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->email->Location = System::Drawing::Point(700, 307);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(45, 19);
			this->email->TabIndex = 12;
			this->email->Text = L"email";//gcnew String (email); 
			// 
			// timetable
			// 
			this->timetable->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timetable->Location = System::Drawing::Point(123, 404);
			this->timetable->Name = L"timetable";
			this->timetable->Size = System::Drawing::Size(308, 55);
			this->timetable->TabIndex = 7;
			this->timetable->Text = L"TIMETABLE";
			this->timetable->UseVisualStyleBackColor = true;
			// 
			// updateDetails
			// 
			this->updateDetails->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updateDetails->Location = System::Drawing::Point(812, 404);
			this->updateDetails->Name = L"updateDetails";
			this->updateDetails->Size = System::Drawing::Size(239, 55);
			this->updateDetails->TabIndex = 8;
			this->updateDetails->Text = L"Update Details";
			this->updateDetails->UseVisualStyleBackColor = true;
			// 
			// student
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1200, 471);
			this->Controls->Add(this->timetable);
			this->Controls->Add(this->updateDetails);
			this->Controls->Add(this->email);
			this->Controls->Add(this->birthday);
			this->Controls->Add(this->deptName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->namelabel);
			this->Controls->Add(this->groupbox);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"student";
			this->Text = L"student";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupbox->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();
			mysql_free_result(ress);
		}
#pragma endregion
};
}
