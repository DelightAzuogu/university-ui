#pragma once
#include <mysql.h>
#include <string>
#include <cctype>
#include <cstring>
#include <iostream>
#include "AddCourse.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	string FacultyNAme;

	/// <summary>
	/// Summary for cordCourse
	/// </summary>
	public ref class cordCourse : public System::Windows::Forms::Form
	{
		MYSQL* con;
		MYSQL_RES* res;
	private: System::Windows::Forms::Button^ removePButton;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

		   MYSQL_ROW row;
	public:
		cordCourse(string facultyNamePara)
		{
			FacultyNAme = facultyNamePara;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			string query = "select course_code from course, department where course.dept_name = department.dept_name and faculty like \"%" + FacultyNAme + "%\" and course.status = true;";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				res = mysql_store_result(con);
				while ((row = mysql_fetch_row(res)) != NULL) {
					string courseCode(row[0]);
					query = "select prereq_code from prereq where course_code like  \"%" + courseCode + "%\";";
					check = mysql_query(con, query.c_str());
					if (!check) {
						MYSQL_RES* resCode = mysql_store_result(con);
						MYSQL_ROW rowCode;
						string prereq = courseCode + "--->";
						while ((rowCode = mysql_fetch_row(resCode)) != NULL) {
							string c(rowCode[0]);
							prereq += c + ",";
						}
						prereqlist->Items->Add(gcnew String(prereq.c_str()));
					}
				}
			}
			mysql_free_result(res);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~cordCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ codeBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ codeError;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ prereqCode;
	private: System::Windows::Forms::Label^ prereqError;


	private: System::Windows::Forms::Button^ addPButton;


	private: System::Windows::Forms::ListBox^ prereqlist;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->codeBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->codeError = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->prereqCode = (gcnew System::Windows::Forms::TextBox());
			this->prereqError = (gcnew System::Windows::Forms::Label());
			this->addPButton = (gcnew System::Windows::Forms::Button());
			this->prereqlist = (gcnew System::Windows::Forms::ListBox());
			this->removePButton = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(100, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(221, 58);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add Course";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &cordCourse::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(461, 175);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 58);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Edit Course";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &cordCourse::button2_Click);
			// 
			// codeBox
			// 
			this->codeBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->codeBox->Location = System::Drawing::Point(127, 195);
			this->codeBox->MaxLength = 10;
			this->codeBox->Name = L"codeBox";
			this->codeBox->Size = System::Drawing::Size(224, 20);
			this->codeBox->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(50, 197);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 15);
			this->label1->TabIndex = 3;
			this->label1->Text = L"course Code";
			// 
			// codeError
			// 
			this->codeError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->codeError->AutoSize = true;
			this->codeError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->codeError->Location = System::Drawing::Point(124, 218);
			this->codeError->Name = L"codeError";
			this->codeError->Size = System::Drawing::Size(22, 15);
			this->codeError->TabIndex = 4;
			this->codeError->Text = L"     ";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(17, 281);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 15);
			this->label2->TabIndex = 6;
			this->label2->Text = L"prereq course code";
			// 
			// prereqCode
			// 
			this->prereqCode->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->prereqCode->Location = System::Drawing::Point(127, 279);
			this->prereqCode->MaxLength = 10;
			this->prereqCode->Name = L"prereqCode";
			this->prereqCode->Size = System::Drawing::Size(224, 20);
			this->prereqCode->TabIndex = 5;
			// 
			// prereqError
			// 
			this->prereqError->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->prereqError->AutoSize = true;
			this->prereqError->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->prereqError->Location = System::Drawing::Point(124, 302);
			this->prereqError->Name = L"prereqError";
			this->prereqError->Size = System::Drawing::Size(22, 15);
			this->prereqError->TabIndex = 7;
			this->prereqError->Text = L"     ";
			// 
			// addPButton
			// 
			this->addPButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addPButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addPButton->Location = System::Drawing::Point(357, 258);
			this->addPButton->Name = L"addPButton";
			this->addPButton->Size = System::Drawing::Size(146, 58);
			this->addPButton->TabIndex = 9;
			this->addPButton->Text = L"Add Prereq";
			this->addPButton->UseVisualStyleBackColor = true;
			this->addPButton->Click += gcnew System::EventHandler(this, &cordCourse::addPButton_Click);
			// 
			// prereqlist
			// 
			this->prereqlist->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->prereqlist->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->prereqlist->FormattingEnabled = true;
			this->prereqlist->Location = System::Drawing::Point(43, 342);
			this->prereqlist->Name = L"prereqlist";
			this->prereqlist->Size = System::Drawing::Size(636, 225);
			this->prereqlist->TabIndex = 10;
			// 
			// removePButton
			// 
			this->removePButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->removePButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->removePButton->Location = System::Drawing::Point(560, 258);
			this->removePButton->Name = L"removePButton";
			this->removePButton->Size = System::Drawing::Size(119, 58);
			this->removePButton->TabIndex = 11;
			this->removePButton->Text = L"Remove Prereq";
			this->removePButton->UseVisualStyleBackColor = true;
			this->removePButton->Click += gcnew System::EventHandler(this, &cordCourse::removePButton_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(357, 175);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(98, 58);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Remove Course";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &cordCourse::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(560, 174);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(91, 58);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Activate";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &cordCourse::button4_Click);
			// 
			// cordCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(721, 589);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->removePButton);
			this->Controls->Add(this->prereqlist);
			this->Controls->Add(this->addPButton);
			this->Controls->Add(this->prereqError);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->prereqCode);
			this->Controls->Add(this->codeError);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->codeBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"cordCourse";
			this->Text = L"Course";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AddCourse^ obj = gcnew AddCourse(FacultyNAme);
		obj->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		string code((const char*)(Marshal::StringToHGlobalAnsi(codeBox->Text)).ToPointer());

		string query = "select * from course where course_code = \"" + code + "\";";
		int check = mysql_query(con, query.c_str());
		if (!check) {
			MYSQL_RES* res = mysql_store_result(con);
			int count = mysql_num_rows(res);
			if (count > 0) {

				AddCourse^ obj = gcnew AddCourse(code, 1);
				obj->ShowDialog();
			}
			else {
				codeError->Text = "invalid course code";
			}
		}
	}
	private: System::Void removePButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string codeC((const char*)(Marshal::StringToHGlobalAnsi(codeBox->Text)).ToPointer());  //c_code string to usable form
		string codeP((const char*)(Marshal::StringToHGlobalAnsi(prereqCode->Text)).ToPointer()); //p_code string to usable form

		string query = "select * from course where course_code = \"" + codeC + "\";";
		int check1 = mysql_query(con, query.c_str());
		if (!check1) {
			MYSQL_RES* res = mysql_store_result(con);
			int count = mysql_num_rows(res);
			if (count <= 0) {
				codeError->Text = "invalid course code";
			}
		}//if course doesn't exist then error

		query = "select * from course where course_code = \"" + codeP + "\";";
		int check2 = mysql_query(con, query.c_str());
		if (!check2) {
			MYSQL_RES* res = mysql_store_result(con);
			int count = mysql_num_rows(res);
			if (count <= 0) {
				prereqError->Text = "invalid course code";
			}
		}//if prereq doesn't exist then error

		if (!check1 && !check2) {
			query = "delete from prereq where course_code = \"" + codeC + "\" and prereq_code = \"" + codeP + "\";";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				prereqError->Text = "Removed successfully";
			}
			else {
				prereqError->Text = "Removal failed";
			}
		} //delete if course and prerequisite code exist
	}

	private: System::Void addPButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string codeC((const char*)(Marshal::StringToHGlobalAnsi(codeBox->Text)).ToPointer());  //c_code string to usable form
		string codeP((const char*)(Marshal::StringToHGlobalAnsi(prereqCode->Text)).ToPointer()); //p_code string to usable form

		string query = "select * from course where course_code = \"" + codeC + "\";";
		int check1 = mysql_query(con, query.c_str());
		if (!check1) {
			MYSQL_RES* res = mysql_store_result(con);
			int count = mysql_num_rows(res);
			if (count <= 0) {
				codeError->Text = "invalid course code";
			}
		}//if course doesn't exist then error

		query = "select * from course where course_code = \"" + codeP + "\";";
		int check2 = mysql_query(con, query.c_str());
		if (!check2) {
			MYSQL_RES* res = mysql_store_result(con);
			int count = mysql_num_rows(res);
			if (count <= 0) {
				prereqError->Text = "invalid course code";
			}
		}//if prereq doesn't exist then error

		if (!check1 && !check2) {
			query = "insert into prereq values ( \"" + codeP + "\", \"" + codeC + "\" ) "";";
			int check = mysql_query(con, query.c_str());
			if (!check) {
				prereqError->Text = "Added successfully";
			}
			else {
				prereqError->Text = "Addition failed";
			}
		} //delete if course and prerequisite code exist
	}


		   //
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		string codeC((const char*)(Marshal::StringToHGlobalAnsi(codeBox->Text)).ToPointer());  //c_code string to usable form

		string query = "select * from course where course_code = \"" + codeC + "\";";
		int check = mysql_query(con, query.c_str());
		if (!check) {
			MYSQL_RES* res = mysql_store_result(con);
			int count = mysql_num_rows(res);
			if (count <= 0) {
				codeError->Text = "invalid course code";
			}//if course doesn't exist then error

			else {
				query = "update course set status = false where course_code = \"" + codeC + "\";";
				int check1 = mysql_query(con, query.c_str());
				if (!check) {
					query = "delete from prereq where course_code = \"" + codeC + "\" or prereq_code = \"" + codeC + "\";";
					check = mysql_query(con, query.c_str());
					if (!check) {
						codeError->Text = "Course removed successfully";
					}
					else {
						codeError->Text = "Course removal failure";
					}//remove course if it exists
				}

			}
		}

	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		codeError->Text = "    ";
		string codeC((const char*)(Marshal::StringToHGlobalAnsi(codeBox->Text)).ToPointer());  //c_code string to usable form

		string query = "select * from course where course_code = \"" + codeC + "\";";
		int check = mysql_query(con, query.c_str());
		if (!check) {
			res = mysql_store_result(con);
			int count = mysql_num_rows(res);
			if (count <= 0) {
				codeError->Text = "invalid course code";
			}//if course doesn't exist then error

			else {
				query = "update course set status = true where course_code = \"" + codeC + "\";";
				check = mysql_query(con, query.c_str());
				if (!check) {
					codeError->Text = "Activated";
				}
				else {
					codeError->Text = "Course activation failure";
				}
			}
			mysql_free_result(res);
		}
	}
	};
}
