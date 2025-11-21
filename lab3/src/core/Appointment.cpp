#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
#include <algorithm>

Appointment::Appointment(const std::string& id, const std::string& date, const std::string& time)
    : id(id), date(date), time(time), durationMinutes(30), status("SCHEDULED"), reason(""), doctor(nullptr), patient(nullptr) {}

double Appointment::calculateOverlapRisk() const {
    double baseRisk = 10.0;
    
    double durationRisk = 0.0;
    if (durationMinutes > 60) durationRisk = 20.0;
    else if (durationMinutes > 30) durationRisk = 10.0;
    
    double doctorRisk = doctor ? 5.0 : 15.0;
    double patientRisk = patient ? (patient->calculateHealthRiskScore() * 0.1) : 10.0;
    
    double timeRisk = 0.0;
    if (time == "09:00" || time == "14:00") timeRisk = 5.0;
    
    double totalRisk = baseRisk + durationRisk + doctorRisk + patientRisk + timeRisk;
    return std::min(totalRisk, 100.0);
}

bool Appointment::canBeRescheduled() const {
    bool isUrgent = reason.find("emergency") != std::string::npos || 
                   reason.find("urgent") != std::string::npos;
    
    bool hasHighPriorityPatient = patient && patient->determinePriorityLevel() == "HIGH";
    bool isLongDuration = durationMinutes > 45;
    bool involvesSpecialist = doctor && (doctor->getSpecialization() == "Cardiology" || 
                                        doctor->getSpecialization() == "Neurology");
    
    return !isUrgent && !hasHighPriorityPatient && !isLongDuration && !involvesSpecialist;
}

double Appointment::calculateUrgencyScore() const {
    double baseScore = 30.0;
    
    double reasonScore = 0.0;
    if (reason.find("emergency") != std::string::npos) reasonScore = 40.0;
    else if (reason.find("follow-up") != std::string::npos) reasonScore = 20.0;
    else if (reason.find("check-up") != std::string::npos) reasonScore = 10.0;
    
    double patientScore = patient ? (patient->calculateHealthRiskScore() * 0.5) : 0.0;
    double doctorScore = doctor ? (doctor->getExperienceYears() * 0.5) : 0.0;
    double durationScore = durationMinutes * 0.2;
    
    double totalScore = baseScore + reasonScore + patientScore + doctorScore + durationScore;
    return std::min(totalScore, 100.0);
}

void Appointment::setDoctor(Doctor* doctor) {
    this->doctor = doctor;
}

Doctor* Appointment::getDoctor() const {
    return doctor;
}

void Appointment::setPatient(Patient* patient) {
    this->patient = patient;
}

Patient* Appointment::getPatient() const {
    return patient;
}
