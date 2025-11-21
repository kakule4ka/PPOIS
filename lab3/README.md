## Классы:

1. **Hospital** (5 полей, 5 методов) → MedicalDepartment, Patient
2. **MedicalDepartment** (8 полей, 4 метода) → Doctor, Patient
3. **Doctor** (6 полей, 5 методов) → Patient, Appointment
4. **Patient** (8 полей, 5 методов) → MedicalRecord, TreatmentPlan
5. **Appointment** (8 полей, 3 метода) → Doctor, Patient
6. **MedicalRecord** (7 полей, 5 методов) → Patient, Diagnosis
7. **Diagnosis** (8 полей, 3 метода) → MedicalRecord, TreatmentPlan
8. **TreatmentPlan** (8 полей, 5 методов) → Patient, Medication
9. **Medication** (8 полей, 5 методов) → TreatmentPlan, Patient
10. **Prescription** (8 полей, 5 методов) → Patient, Doctor, Medication
11. **Billing** (9 полей, 3 метода) → Patient, TreatmentPlan, Insurance
12. **Insurance** (8 полей, 3 метода) → Patient, Billing
13. **LaboratoryTest** (8 полей, 3 метода) → Patient, Doctor
14. **MedicalEquipment** (8 полей, 3 метода) → MedicalDepartment, Patient
15. **MedicalDevice** (8 полей, 3 метода) → Patient, Doctor
16. **Nurse** (8 полей, 3 метода) → Patient, MedicalDepartment
17. **EmergencyCase** (9 полей, 3 метода) → Patient, Doctor, MedicalDepartment
18. **Ward** (8 полей, 3 метода) → Patient, Nurse, MedicalDepartment
19. **ICU** (8 полей, 3 метода) → Patient, Nurse, MedicalEquipment
20. **PatientRoom** (8 полей, 3 метода) → Patient, Nurse, MedicalEquipment
21. **OperatingRoom** (9 полей, 3 метода) → Surgery, MedicalEquipment, Doctor
22. **Surgery** (9 полей, 3 метода) → Patient, Doctor, OperatingRoom
23. **Ambulance** (9 полей, 3 метода) → Patient, EmergencyCase, MedicalEquipment
24. **BloodTest** (9 полей, 3 метода) → Patient, Doctor
25. **Pharmacy** (8 полей, 3 метода) → Medication, Patient, Doctor
26. **Vaccine** (8 полей, 3 метода) → Patient, Pediatrician
27. **MentalHealthTherapy** (6 полей, 3 метода) → Patient, TreatmentPlan
28. **Rehabilitation** (7 полей, 3 метода) → Patient, PhysicalTherapist, TreatmentPlan
29. **PhysicalTherapy** (7 полей, 3 метода) → Patient, Rehabilitation
30. **RehabilitationSpecialist** (5 полей, 2 метода) → Patient
31. **PhysicalTherapist** (5 полей, 2 метода) → Patient
32. **Cardiologist** (8 полей, 3 метода) : Doctor → Patient, MedicalEquipment
33. **Neurologist** (7 полей, 3 метода) : Doctor → Patient, LaboratoryTest
34. **Pediatrician** (7 полей, 3 метода) : Doctor → Patient, Vaccine
35. **Surgeon** (7 полей, 3 метода) : Doctor → Surgery, OperatingRoom
36. **Radiologist** (6 полей, 2 метода) : Doctor → MedicalDevice
37. **XRay** (7 полей, 3 метода) : MedicalDevice → Patient, Radiologist
38. **MRI** (8 полей, 3 метода) : MedicalDevice → Patient, Radiologist
39. **AnalyticsService** (3 поля, 6 методов) → Hospital, Patient
40. **AppointmentService** (4 поля, 6 методов) → Appointment, Doctor, Patient
41. **BillingService** (5 полей, 6 методов) → Billing, Patient, Insurance
42. **ComplianceService** (2 поля, 3 метода) → Hospital
43. **DoctorSchedulingService** (2 поля, 3 метода) → Doctor
44. **EmergencyService** (2 поля, 3 метода) → EmergencyCase
45. **InsuranceService** (2 поля, 3 метода) → Insurance
46. **LaboratoryService** (2 поля, 3 метода) → LaboratoryTest
47. **MedicalRecordsService** (2 поля, 3 метода) → MedicalRecord
48. **PatientManagementService** (2 поля, 3 метода) → Patient
49. **PharmacyService** (2 поля, 3 метода) → Pharmacy
50. **ResourceManagementService** (2 поля, 3 метода) → Hospital

## Исключения:

1. **BedNotAvailableException** (4 поля, 3 метода)
2. **BillingException** (4 поля, 4 метода)
3. **DoctorNotAvailableException** (2 поля, 2 метода)
4. **EmergencyPriorityException** (3 поля, 3 метода)
5. **InsuranceNotCoveredException** (3 поля, 3 метода)
6. **LaboratoryTestFailedException** (3 поля, 3 метода)
7. **MedicalEquipmentFailureException** (2 поля, 2 метода)
8. **MedicalRecordAccessException** (3 поля, 3 метода)
9. **MedicationNotAvailableException** (3 поля, 3 метода)
10. **PatientNotFoundException** (1 поле, 1 метод)
11. **PrescriptionInvalidException** (3 поля, 3 метода)
12. **SurgeryRiskException** (4 поля, 4 метода)

## Всего:

- **Классов**: 50
- **Персональных исключений**: 12
- **Всего полей**: 337
- **Уникальных методов (без геттеров/сеттеров)**: 172
- **Ассоциаций между классами**: 78
