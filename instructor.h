#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <mysql.h>
#include "iChangePassword.h"
#include "iTime.h"
#include "iUpdateDetails.h"
#include "iCourse.h"

std::string isemester;
std::string iId;
char* iCourseCode[7];
char* iGroup[7];

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
	/// Summary for instructor
	/// </summary>
	public ref class instructor : public System::Windows::Forms::Form
	{
		int year;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ comment;
		   Form^ login;
	public:
		instructor(Form^ loginPara, string id, int yearPara, String^ semesterPara)
		{
			login = loginPara;
			iId = id;
			year = yearPara;
			string semesterString((const char*)(Marshal::StringToHGlobalAnsi(semesterPara)).ToPointer());
			isemester = semesterString;

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			MYSQL* con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			int count = 0;

			MYSQL_RES* ress;

			if (con) {
				string query1 = "select course_code,group_number from teaches where i_id = " + id + " and semester = \"" + semesterString + "\" and year = " + to_string(yearPara) + "; ";
				int check = mysql_query(con, query1.c_str());
				if (!check) {
					ress = mysql_store_result(con);
					count = mysql_num_rows(ress);
				}

			}

			MYSQL_ROW roww;


			for (int i = 0; i < count; i++) {
				roww = mysql_fetch_row(ress);
				iCourseCode[i] = roww[0];
				iGroup[i] = roww[1];
			}
			//intializations of button points
			if (count >= 1) {
				this->course1->Location = System::Drawing::Point(24, 36);
				this->course1->Text = gcnew String(iCourseCode[0]);
			}
			if (count >= 2) {
				this->course2->Location = System::Drawing::Point(202, 36);
				this->course2->Text = gcnew String(iCourseCode[1]);

			}
			if (count >= 3) {
				this->course3->Location = System::Drawing::Point(380, 36);
				this->course3->Text = gcnew String(iCourseCode[2]);
			}
			if (count >= 4) {
				this->course4->Location = System::Drawing::Point(24, 155);
				this->course4->Text = gcnew String(iCourseCode[3]);
			}
			if (count >= 5) {
				this->course5->Location = System::Drawing::Point(202, 155);
				this->course5->Text = gcnew String(iCourseCode[4]);
			}
			if (count == 6) {
				this->course6->Location = System::Drawing::Point(380, 155);
				this->course6->Text = gcnew String(iCourseCode[5]);

			}


			//connection 2
			MYSQL* con2 = mysql_init(NULL);
			con2 = mysql_real_connect(con2, "localhost", "root", "password", "logo_university", 3306, NULL, 0);

			MYSQL_RES* res2;
			MYSQL_ROW row2;

			char name[50] = "";

			if (con2) {
				string query2 = "select first_name, last_name, instructor.dept_name, email,faculty from instructor, department where id = " + id + " and instructor.dept_name = department.dept_name;";
				int check2 = mysql_query(con2, query2.c_str());
				if (!check2) {
					res2 = mysql_store_result(con2); //stores the result of the query

					if (mysql_num_rows(res2) == 0) {// if the query returns no rows 
						exit(1);
					}
					else {

						row2 = mysql_fetch_row(res2); //stores the row containing the details

						strcat(name, row2[0]);
						strcat(name, " ");
						strcat(name, row2[1]);
						this->name->Text = gcnew String(name);
						this->id->Text = gcnew String(id.c_str());
						this->deptName->Text = gcnew String(row2[2]);
						this->email->Text = gcnew String(row2[3]);
						string faculty(row2[4]);
						query2 = "select comment from faculty where faculty_name = \"" + faculty + "\";";
						cout << query2 << endl;
						check2 = mysql_query(con2, query2.c_str());
						if (!check2) {
							res2 = mysql_store_result(con2);
							row2 = mysql_fetch_row(res2);
							comment->Text = gcnew String(row2[0]);
						}
					}

				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~instructor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ logout;
	private: System::Windows::Forms::ToolStripMenuItem^ changepassword;
	private: System::Windows::Forms::Button^ course6;
	private: System::Windows::Forms::Button^ course5;
	private: System::Windows::Forms::Button^ course4;
	private: System::Windows::Forms::Button^ course3;
	private: System::Windows::Forms::Button^ course2;
	private: System::Windows::Forms::Button^ course1;
	private: System::Windows::Forms::Button^ timeTable;
	private: System::Windows::Forms::Button^ updateButton;
	private: System::Windows::Forms::Label^ email;
	private: System::Windows::Forms::Label^ deptName;
	private: System::Windows::Forms::Label^ id;
	private: System::Windows::Forms::Label^ name;
	private: System::Windows::Forms::GroupBox^ groupBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(instructor::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->logout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changepassword = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->course6 = (gcnew System::Windows::Forms::Button());
			this->course5 = (gcnew System::Windows::Forms::Button());
			this->course4 = (gcnew System::Windows::Forms::Button());
			this->course3 = (gcnew System::Windows::Forms::Button());
			this->course2 = (gcnew System::Windows::Forms::Button());
			this->course1 = (gcnew System::Windows::Forms::Button());
			this->timeTable = (gcnew System::Windows::Forms::Button());
			this->updateButton = (gcnew System::Windows::Forms::Button());
			this->email = (gcnew System::Windows::Forms::Label());
			this->deptName = (gcnew System::Windows::Forms::Label());
			this->id = (gcnew System::Windows::Forms::Label());
			this->name = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->comment = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->logout, this->changepassword });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->menuStrip1->Size = System::Drawing::Size(885, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// logout
			// 
			this->logout->BackColor = System::Drawing::Color::Firebrick;
			this->logout->Name = L"logout";
			this->logout->Size = System::Drawing::Size(55, 20);
			this->logout->Text = L"logout";
			this->logout->Click += gcnew System::EventHandler(this, &instructor::logout_Click);
			// 
			// changepassword
			// 
			this->changepassword->BackColor = System::Drawing::Color::SteelBlue;
			this->changepassword->Name = L"changepassword";
			this->changepassword->Size = System::Drawing::Size(114, 20);
			this->changepassword->Text = L"change password";
			this->changepassword->Click += gcnew System::EventHandler(this, &instructor::changepassword_Click);
			// 
			// course6
			// 
			this->course6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course6->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->course6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->course6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course6->Location = System::Drawing::Point(32723, 32564);
			this->course6->Name = L"course6";
			this->course6->Size = System::Drawing::Size(148, 88);
			this->course6->TabIndex = 6;
			this->course6->Text = L"button6";
			this->course6->UseVisualStyleBackColor = false;
			this->course6->Click += gcnew System::EventHandler(this, &instructor::course6_Click);
			// 
			// course5
			// 
			this->course5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course5->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->course5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->course5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course5->Location = System::Drawing::Point(32723, 32564);
			this->course5->Name = L"course5";
			this->course5->Size = System::Drawing::Size(148, 88);
			this->course5->TabIndex = 5;
			this->course5->Text = L"button5";
			this->course5->UseVisualStyleBackColor = false;
			this->course5->Click += gcnew System::EventHandler(this, &instructor::course5_Click);
			// 
			// course4
			// 
			this->course4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course4->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->course4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->course4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course4->Location = System::Drawing::Point(5524, 32564);
			this->course4->Name = L"course4";
			this->course4->Size = System::Drawing::Size(148, 88);
			this->course4->TabIndex = 4;
			this->course4->Text = L"button4";
			this->course4->UseVisualStyleBackColor = false;
			this->course4->Click += gcnew System::EventHandler(this, &instructor::course4_Click);
			// 
			// course3
			// 
			this->course3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->course3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->course3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course3->Location = System::Drawing::Point(32723, 5536);
			this->course3->Name = L"course3";
			this->course3->Size = System::Drawing::Size(148, 88);
			this->course3->TabIndex = 3;
			this->course3->Text = L"button3";
			this->course3->UseVisualStyleBackColor = false;
			this->course3->Click += gcnew System::EventHandler(this, &instructor::course3_Click);
			// 
			// course2
			// 
			this->course2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->course2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->course2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course2->Location = System::Drawing::Point(32723, 5536);
			this->course2->Name = L"course2";
			this->course2->Size = System::Drawing::Size(148, 88);
			this->course2->TabIndex = 2;
			this->course2->Text = L"button2";
			this->course2->UseVisualStyleBackColor = false;
			this->course2->Click += gcnew System::EventHandler(this, &instructor::course2_Click);
			// 
			// course1
			// 
			this->course1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->course1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->course1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->course1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->course1->Location = System::Drawing::Point(5524, 5536);
			this->course1->Name = L"course1";
			this->course1->Size = System::Drawing::Size(148, 88);
			this->course1->TabIndex = 1;
			this->course1->Text = L"button1";
			this->course1->UseVisualStyleBackColor = false;
			this->course1->Click += gcnew System::EventHandler(this, &instructor::course1_Click);
			// 
			// timeTable
			// 
			this->timeTable->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->timeTable->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeTable->Location = System::Drawing::Point(70, 408);
			this->timeTable->Name = L"timeTable";
			this->timeTable->Size = System::Drawing::Size(403, 55);
			this->timeTable->TabIndex = 23;
			this->timeTable->Text = L"Time Table";
			this->timeTable->UseVisualStyleBackColor = true;
			this->timeTable->Click += gcnew System::EventHandler(this, &instructor::timeTable_Click);
			// 
			// updateButton
			// 
			this->updateButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->updateButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updateButton->Location = System::Drawing::Point(28, 190);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(199, 55);
			this->updateButton->TabIndex = 22;
			this->updateButton->Text = L"Update Details";
			this->updateButton->UseVisualStyleBackColor = true;
			this->updateButton->Click += gcnew System::EventHandler(this, &instructor::updateButton_Click);
			// 
			// email
			// 
			this->email->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->email->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->email->Location = System::Drawing::Point(10, 120);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(239, 16);
			this->email->TabIndex = 21;
			this->email->Text = L"semester";
			// 
			// deptName
			// 
			this->deptName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->deptName->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deptName->Location = System::Drawing::Point(10, 83);
			this->deptName->Name = L"deptName";
			this->deptName->Size = System::Drawing::Size(277, 37);
			this->deptName->TabIndex = 20;
			this->deptName->Text = L"dept_name";
			// 
			// id
			// 
			this->id->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->id->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id->Location = System::Drawing::Point(7, 54);
			this->id->Name = L"id";
			this->id->Size = System::Drawing::Size(43, 15);
			this->id->TabIndex = 19;
			this->id->Text = L"id";
			// 
			// name
			// 
			this->name->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(3, 15);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(277, 19);
			this->name->TabIndex = 18;
			this->name->Text = L"Name";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->course6);
			this->groupBox1->Controls->Add(this->course5);
			this->groupBox1->Controls->Add(this->course4);
			this->groupBox1->Controls->Add(this->course3);
			this->groupBox1->Controls->Add(this->course2);
			this->groupBox1->Controls->Add(this->course1);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(13, 126);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(574, 267);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"COURSES";
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->updateButton);
			this->panel1->Controls->Add(this->email);
			this->panel1->Controls->Add(this->deptName);
			this->panel1->Controls->Add(this->id);
			this->panel1->Controls->Add(this->name);
			this->panel1->Location = System::Drawing::Point(593, 138);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(292, 255);
			this->panel1->TabIndex = 24;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(72, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(371, 42);
			this->label4->TabIndex = 26;
			this->label4->Text = L"LOGO UNIVERSITY";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(16, 38);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 44);
			this->pictureBox2->TabIndex = 25;
			this->pictureBox2->TabStop = false;
			// 
			// comment
			// 
			this->comment->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comment->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->comment->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->comment->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comment->Location = System::Drawing::Point(12, 476);
			this->comment->Name = L"comment";
			this->comment->Size = System::Drawing::Size(861, 122);
			this->comment->TabIndex = 27;
			this->comment->Text = L"       ";
			// 
			// instructor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(885, 626);
			this->Controls->Add(this->comment);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->timeTable);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimumSize = System::Drawing::Size(901, 494);
			this->Name = L"instructor";
			this->Text = L"instructor";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void logout_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		login->Show();
	}
	private: System::Void changepassword_Click(System::Object^ sender, System::EventArgs^ e) {
		iChangePassword^ obj = gcnew iChangePassword(iId);
		obj->ShowDialog();
	}
	private: System::Void timeTable_Click(System::Object^ sender, System::EventArgs^ e) {
		iTime^ obj = gcnew iTime(iId, year, isemester, iGroup, iCourseCode);
		obj->ShowDialog();
	}
	private: System::Void updateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		iUpdateDetails^ obj = gcnew iUpdateDetails(iId);
		obj->ShowDialog();
	}
	private: System::Void course1_Click(System::Object^ sender, System::EventArgs^ e) {
		iCourse^ obj = gcnew iCourse(iCourseCode[0], year, isemester);
		obj->ShowDialog();
	}
	private: System::Void course2_Click(System::Object^ sender, System::EventArgs^ e) {
		iCourse^ obj = gcnew iCourse(iCourseCode[1], year, isemester);
		obj->ShowDialog();
	}
	private: System::Void course3_Click(System::Object^ sender, System::EventArgs^ e) {
		iCourse^ obj = gcnew iCourse(iCourseCode[2], year, isemester);
		obj->ShowDialog();
	}
	private: System::Void course4_Click(System::Object^ sender, System::EventArgs^ e) {
		iCourse^ obj = gcnew iCourse(iCourseCode[3], year, isemester);
		obj->ShowDialog();
	}
	private: System::Void course5_Click(System::Object^ sender, System::EventArgs^ e) {
		iCourse^ obj = gcnew iCourse(iCourseCode[4], year, isemester);
		obj->ShowDialog();
	}
	private: System::Void course6_Click(System::Object^ sender, System::EventArgs^ e) {
		iCourse^ obj = gcnew iCourse(iCourseCode[5], year, isemester);
		obj->ShowDialog();
	}
	};
}
