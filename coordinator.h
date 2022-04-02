#pragma once
#include <mysql.h>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cstring>
#include "summerSemester.h"
#include <iostream>
#include "cordStudent.h"
#include "cordCourse.h"
#include "cordInstructor.h"
#include "iChangePassword.h"


namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	string facultyName;
	string idC;
	string semester;
	/// <summary>
	/// Summary for coordinator
	/// </summary>
	public ref class coordinator : public System::Windows::Forms::Form
	{
		Form^ login;
		MYSQL* con;
	private: System::Windows::Forms::ToolStripMenuItem^ changePasswordToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ currentStudent;
	private: System::Windows::Forms::TextBox^ comment;

	private: System::Windows::Forms::Button^ addcommentButton;
	private: System::Windows::Forms::Label^ label1;

		   int year;
	public:
		coordinator(Form^ loginPara, string idPara, int yearPara, String^ semesterPara)
		{
			login = loginPara;
			string s((char*)(Marshal::StringToHGlobalAnsi(semesterPara)).ToPointer());
			semester = s;
			year = yearPara;

			con = mysql_init(NULL);
			con = mysql_real_connect(con, "localhost", "root", "password", "logo_university", 3306, NULL, 0);
			if (!con) {
				exit(1);
			}
			idC = idPara;
			string query = "select faculty_name from coordinator where i_id = " + idC + ";";

			int check = mysql_query(con, query.c_str());

			MYSQL_RES* res;
			MYSQL_ROW row;

			if (!check) {
				res = mysql_store_result(con);
				row = mysql_fetch_row(res);
				string f(row[0]);
				facultyName = f;
			}

			

			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			query = "select id from student as S, department as D where current_semester = true and S.dept_name = D.dept_name and faculty = \"" + facultyName + "\";";
			check = mysql_query(con, query.c_str());
			if (!check) {
				res = mysql_store_result(con);
				while((row = mysql_fetch_row(res)) != NULL) {
					currentStudent->Items->Add(gcnew String(row[0]));
				}
			}
			query = "select comment from faculty where faculty_name = \"" + facultyName + "\";";
			check = mysql_query(con, query.c_str());
			if (!check) {
				res = mysql_store_result(con);
				row = mysql_fetch_row(res);
				this->comment->Text = gcnew String(row[0]);
			}
			mysql_free_result(res);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~coordinator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ studentButton;
	protected:
	private: System::Windows::Forms::Button^ instructorButton;
	private: System::Windows::Forms::Button^ courseButton;


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem;

	private: System::Windows::Forms::Button^ startSpring;
	private: System::Windows::Forms::Button^ endSemester;


	private: System::Windows::Forms::Button^ startSummer;
	private: System::Windows::Forms::Button^ startFall;



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
			this->studentButton = (gcnew System::Windows::Forms::Button());
			this->instructorButton = (gcnew System::Windows::Forms::Button());
			this->courseButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->logoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changePasswordToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startSpring = (gcnew System::Windows::Forms::Button());
			this->endSemester = (gcnew System::Windows::Forms::Button());
			this->startSummer = (gcnew System::Windows::Forms::Button());
			this->startFall = (gcnew System::Windows::Forms::Button());
			this->currentStudent = (gcnew System::Windows::Forms::ListBox());
			this->comment = (gcnew System::Windows::Forms::TextBox());
			this->addcommentButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// studentButton
			// 
			this->studentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->studentButton->Location = System::Drawing::Point(91, 127);
			this->studentButton->Name = L"studentButton";
			this->studentButton->Size = System::Drawing::Size(235, 72);
			this->studentButton->TabIndex = 0;
			this->studentButton->Text = L"Student";
			this->studentButton->UseVisualStyleBackColor = true;
			this->studentButton->Click += gcnew System::EventHandler(this, &coordinator::studentButton_Click);
			// 
			// instructorButton
			// 
			this->instructorButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->instructorButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instructorButton->Location = System::Drawing::Point(91, 205);
			this->instructorButton->Name = L"instructorButton";
			this->instructorButton->Size = System::Drawing::Size(235, 72);
			this->instructorButton->TabIndex = 1;
			this->instructorButton->Text = L"Instructor";
			this->instructorButton->UseVisualStyleBackColor = true;
			this->instructorButton->Click += gcnew System::EventHandler(this, &coordinator::instructorButton_Click);
			// 
			// courseButton
			// 
			this->courseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->courseButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->courseButton->Location = System::Drawing::Point(91, 283);
			this->courseButton->Name = L"courseButton";
			this->courseButton->Size = System::Drawing::Size(235, 72);
			this->courseButton->TabIndex = 2;
			this->courseButton->Text = L"Course";
			this->courseButton->UseVisualStyleBackColor = true;
			this->courseButton->Click += gcnew System::EventHandler(this, &coordinator::courseButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->logoutToolStripMenuItem,
					this->changePasswordToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->menuStrip1->Size = System::Drawing::Size(791, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// logoutToolStripMenuItem
			// 
			this->logoutToolStripMenuItem->BackColor = System::Drawing::Color::Maroon;
			this->logoutToolStripMenuItem->Name = L"logoutToolStripMenuItem";
			this->logoutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->logoutToolStripMenuItem->Text = L"logout";
			this->logoutToolStripMenuItem->Click += gcnew System::EventHandler(this, &coordinator::logoutToolStripMenuItem_Click);
			// 
			// changePasswordToolStripMenuItem
			// 
			this->changePasswordToolStripMenuItem->BackColor = System::Drawing::Color::CadetBlue;
			this->changePasswordToolStripMenuItem->Name = L"changePasswordToolStripMenuItem";
			this->changePasswordToolStripMenuItem->Size = System::Drawing::Size(107, 20);
			this->changePasswordToolStripMenuItem->Text = L"change Password";
			this->changePasswordToolStripMenuItem->Click += gcnew System::EventHandler(this, &coordinator::changePasswordToolStripMenuItem_Click);
			// 
			// startSpring
			// 
			this->startSpring->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->startSpring->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startSpring->Location = System::Drawing::Point(12, 85);
			this->startSpring->Name = L"startSpring";
			this->startSpring->Size = System::Drawing::Size(138, 36);
			this->startSpring->TabIndex = 4;
			this->startSpring->Text = L"Start Spring";
			this->startSpring->UseVisualStyleBackColor = true;
			this->startSpring->Click += gcnew System::EventHandler(this, &coordinator::startSpring_Click);
			// 
			// endSemester
			// 
			this->endSemester->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->endSemester->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->endSemester->Location = System::Drawing::Point(91, 361);
			this->endSemester->Name = L"endSemester";
			this->endSemester->Size = System::Drawing::Size(235, 36);
			this->endSemester->TabIndex = 5;
			this->endSemester->Text = L"End Semester";
			this->endSemester->UseVisualStyleBackColor = true;
			this->endSemester->Click += gcnew System::EventHandler(this, &coordinator::endSemester_Click);
			// 
			// startSummer
			// 
			this->startSummer->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->startSummer->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startSummer->Location = System::Drawing::Point(156, 85);
			this->startSummer->Name = L"startSummer";
			this->startSummer->Size = System::Drawing::Size(138, 36);
			this->startSummer->TabIndex = 6;
			this->startSummer->Text = L"Start Summer";
			this->startSummer->UseVisualStyleBackColor = true;
			this->startSummer->Click += gcnew System::EventHandler(this, &coordinator::startSummer_Click);
			// 
			// startFall
			// 
			this->startFall->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->startFall->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startFall->Location = System::Drawing::Point(300, 85);
			this->startFall->Name = L"startFall";
			this->startFall->Size = System::Drawing::Size(138, 36);
			this->startFall->TabIndex = 7;
			this->startFall->Text = L"Start Fall";
			this->startFall->UseVisualStyleBackColor = true;
			this->startFall->Click += gcnew System::EventHandler(this, &coordinator::startFall_Click);
			// 
			// currentStudent
			// 
			this->currentStudent->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->currentStudent->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->currentStudent->FormattingEnabled = true;
			this->currentStudent->Location = System::Drawing::Point(474, 45);
			this->currentStudent->Name = L"currentStudent";
			this->currentStudent->Size = System::Drawing::Size(284, 121);
			this->currentStudent->TabIndex = 8;
			// 
			// comment
			// 
			this->comment->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comment->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->comment->Location = System::Drawing::Point(474, 190);
			this->comment->Multiline = true;
			this->comment->Name = L"comment";
			this->comment->Size = System::Drawing::Size(284, 130);
			this->comment->TabIndex = 9;
			// 
			// addcommentButton
			// 
			this->addcommentButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addcommentButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addcommentButton->Location = System::Drawing::Point(507, 354);
			this->addcommentButton->Name = L"addcommentButton";
			this->addcommentButton->Size = System::Drawing::Size(213, 43);
			this->addcommentButton->TabIndex = 10;
			this->addcommentButton->Text = L"Add Comment";
			this->addcommentButton->UseVisualStyleBackColor = true;
			this->addcommentButton->Click += gcnew System::EventHandler(this, &coordinator::addcommentButton_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(554, 333);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"  ";
			// 
			// coordinator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(791, 409);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->addcommentButton);
			this->Controls->Add(this->comment);
			this->Controls->Add(this->currentStudent);
			this->Controls->Add(this->startFall);
			this->Controls->Add(this->startSummer);
			this->Controls->Add(this->endSemester);
			this->Controls->Add(this->startSpring);
			this->Controls->Add(this->courseButton);
			this->Controls->Add(this->instructorButton);
			this->Controls->Add(this->studentButton);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"coordinator";
			this->Text = L"coordinator";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//start spring
	private: System::Void startSpring_Click(System::Object^ sender, System::EventArgs^ e) {
		string query = "select id from student as S ,department as D where S.dept_name = D.dept_name and faculty = \"" + facultyName + "\";";
		int check = mysql_query(con, query.c_str());
		if (!check) {
			MYSQL_RES* res = mysql_store_result(con);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(res)) != NULL) {
				string id(row[0]);
				query = "update student set current_semester = true, semester_no = semester_no + 1 where id = " + id + " and status = true;";
				mysql_query(con, query.c_str());
			}
		}
	}
		   //start summer
	private: System::Void startSummer_Click(System::Object^ sender, System::EventArgs^ e) {
		summerSemester^ obj = gcnew summerSemester(facultyName);
		obj->ShowDialog();
	}
		   //start fall
	private: System::Void startFall_Click(System::Object^ sender, System::EventArgs^ e) {
		string query = "select id from student as S ,department as D where S.dept_name = D.dept_name and faculty = \"" + facultyName + "\";";
		int check = mysql_query(con, query.c_str());
		if (!check) {
			MYSQL_RES* res = mysql_store_result(con);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(res)) != NULL) {
				string id(row[0]);
				query = "update student set current_semester = true, semester_no = semester_no + 1 where id = " + id + " and status = true;";
				mysql_query(con, query.c_str());
			}
		}
	}
	private: System::Void endSemester_Click(System::Object^ sender, System::EventArgs^ e) {
		string query = "select id from student as S ,department as D where S.status = true and current_semester = true and S.dept_name = D.dept_name and faculty = \"" + facultyName + "\";";
		int check = mysql_query(con, query.c_str());

		if (!check) {
			MYSQL_RES* resStudent = mysql_store_result(con);
			MYSQL_ROW rowStudent;

			while ((rowStudent = mysql_fetch_row(resStudent)) != NULL) {
				string id(rowStudent[0]);
				query = "select grade, course_code from takes where s_id = " + id + " and semester = \"" + semester + "\" and year = " + to_string(year) + ";";
				check = mysql_query(con, query.c_str());


				if (!check) {
					MYSQL_RES* resGrade = mysql_store_result(con);
					MYSQL_ROW rowGrade;

					int count = mysql_num_rows(resGrade);
					float gradeEarned = 0;
					int totalCredit = 0;
					if (count > 0) {
						while ((rowGrade = mysql_fetch_row(resGrade)) != NULL) {
							string grade(rowGrade[0]);
							string courseCode(rowGrade[1]);
							query = "select credit from course where course_code = \"" + courseCode + "\";";
							check = mysql_query(con, query.c_str());

							if (!check) {
								MYSQL_RES* resCredit = mysql_store_result(con);
								MYSQL_ROW rowCredit = mysql_fetch_row(resCredit);
								int credit = atoi(rowCredit[0]);
								totalCredit += credit;
								if (grade == "A") {
									gradeEarned += credit * 4.0;
								}
								else if (grade == "A-") {
									gradeEarned += credit * 3.7;
								}
								else if (grade == "B+") {
									gradeEarned += credit * 3.33;
								}
								else if (grade == "B") {
									gradeEarned += credit * 3.0;
								}
								else if (grade == "B-") {
									gradeEarned += credit * 2.7;
								}
								else if (grade == "C+") {
									gradeEarned += credit * 2.33;
								}
								else if (grade == "C") {
									gradeEarned += credit * 2.0;
								}
								else if (grade == "C-") {
									gradeEarned += credit * 1.7;
								}
								else if (grade == "D+") {
									gradeEarned += credit * 1.33;
								}
								else if (grade == "D") {
									gradeEarned += credit * 1.0;
								}
								else if (grade == "D-") {
									gradeEarned += credit * 0.7;
								}
								else if (grade == "F") {
									gradeEarned += credit * 0.00;
								}
							}

						}
						float gpa = gradeEarned / totalCredit;
						string g = to_string(gpa);
						cout << g << "  asas" << endl;
						query = "insert into student_gpa values (" + id + ", " + g + ", \"" + semester + "\"," + to_string(gradeEarned) + "," + to_string(year) + " );";

						check = mysql_query(con, query.c_str());
						if (!check) {
							cout << "inside" << endl;
							query = "select gpa from student_gpa where s_id = " + id + ";";
							check = mysql_query(con, query.c_str());
							if (!check) {
								MYSQL_RES* resGpa = mysql_store_result(con);
								MYSQL_ROW rowGpa;
								int count = mysql_num_rows(resGpa);
								float totalGpa = 0;
								if (count > 0) {
									while ((rowGpa = mysql_fetch_row(resGpa)) != NULL) {
										gpa = atof(rowGpa[0]);
										totalGpa += gpa;
									}
									float cgpa = totalGpa / count;
									query = "update student set cgpa = " + to_string(cgpa) + ", current_semester = false where id = " + id + ";";
									cout << query;
									mysql_query(con, query.c_str());
								}
							}
						}
					}
					else {
						float gpa = 0;
						string g = to_string(gpa);
						cout << g << "  asas" << endl;
						query = "insert into student_gpa values (" + id + ", " + g + ", \"" + semester + "\"," + to_string(gradeEarned) + "," + to_string(year) + " );";

						check = mysql_query(con, query.c_str());
						if (!check) {
							cout << "inside" << endl;
							query = "select gpa from student_gpa where s_id = " + id + ";";
							check = mysql_query(con, query.c_str());
							if (!check) {
								MYSQL_RES* resGpa = mysql_store_result(con);
								MYSQL_ROW rowGpa;
								int count = mysql_num_rows(resGpa);
								float totalGpa = 0;
								if (count > 0) {
									while ((rowGpa = mysql_fetch_row(resGpa)) != NULL) {
										gpa = atof(rowGpa[0]);
										totalGpa += gpa;
									}
									float cgpa = totalGpa / count;
									query = "update student set cgpa = " + to_string(cgpa) + ", current_semester = false where id = " + id + ";";
									cout << query;
									mysql_query(con, query.c_str());
								}
							}
						}
					}

					
				}
			}
		}

	}
	private: System::Void studentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cordStudent^ obj = gcnew cordStudent(facultyName);
		obj->ShowDialog();
	}
	private: System::Void courseButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cordCourse^ obj = gcnew cordCourse(facultyName);
		obj->ShowDialog();
	}
	private: System::Void instructorButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cordInstructor^ obj = gcnew cordInstructor(facultyName, year, semester);
		obj->ShowDialog();
	}
	private: System::Void logoutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		login->Show();
	}
	private: System::Void changePasswordToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		iChangePassword^ obj = gcnew iChangePassword(idC);
		obj->ShowDialog();
	}
	private: System::Void addcommentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string commentText((const char*)(Marshal::StringToHGlobalAnsi(comment->Text)).ToPointer());
		label1->Text = " ";
		
		string query = "update faculty set comment = \"" + commentText + "\" where faculty_name = \"" + facultyName + "\";";
		int check = mysql_query(con, query.c_str());
		if (!check) {
			label1->Text = "updated";
		}
	}
};
}
