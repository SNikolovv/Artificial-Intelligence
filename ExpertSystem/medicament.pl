prove(true) :- !.

prove((B, Bs)) :- !,prove(B),prove(Bs).

prove((B;Bs)):-!,( prove(B);prove(Bs)).

prove(H) :-
    clause(H, B),
    prove(B).


prove(H) :-
    askable(H),
    writeln(H),
    read(Answer),
	Answer == yes.



drink(X):- has_abdominal_pain(X),has_muscle_pain(X),has_high_blood_pressure(X),
           ( (has_headache(X),medicament12(X)); (has_menstrual_pain(X),medicament11(X));
            medicament13(X);medicament14(X);medicament15(X)).

drink(X):- has_headache(X),
    (( has_temperatyre(X),has_muscle_pain(X),medicament21(X));
                           ((has_abdominal_pain(X);has_joint_pain(X)),medicament22(X));
              (has_stuffy_nose(X),medicament23(X));medicament24(X);medicament25(X)).

drink(X) :- are_you_under_12_years_old(X), 
    (( has_headache(X),has_temperatyre(X), medicament31(X));
    ( has_cough(X),medicament33(X)); 
    (has_you_sore_throat(X),medicament34(X);medicament32(X);medicament35(X))).

drink(X):-has_redness(X),has_rash(X),has_watery_eyes(X),
      ((has_temperature(X),medicament41(X));
       (has_headache(X),medicament42(X));
        medicament43(X);medicament44(X);medicament45(X)).



drink(X) :- has_stuffy_nose(X),has_temperature(X),
    ((are_you_under_12_years_old(X),medicament51(X));
     (has_headache(X),medicament52(X));
    (has_you_taken_medicine_recently(X),medicament53(X));
    (has_low_blood_pressure(X),medicament54(X));
						(has_cough(X),medicament55(X))).



medicament11(no-spa).
medicament12(buskolizin).
medicament13(spazmalgon).
medicament14(dro-spaz).
medicament15(gastritol).

medicament21(analgin).
medicament22(aspirin).       
medicament23(paracetamol).
medicament24(migrenon).
medicament25(alka-zaider).    

medicament31(teraflu).
medicament32(tailolhot).
medicament33(stodal).
medicament34(efizol).
medicament35(gripexmax).

medicament41(alergozan).
medicament42(dermodrin).
medicament43(alergotan).
medicament44(orbazon).
medicament45(alergoprom).

medicament51(ferveks).
medicament52(gripexstop).
medicament53(prostunadal).
medicament54(paracetamol400).
medicament55(coldrex).


askable(has_headache(_)). %главоболие
askable(has_temperature(_)). %температура
askable(has_cough(_)). %кашлица
askable(has_abdominal_pain(_)). %болки в корема
askable(has_high_blood_pressure(_)). %високо кръвно налягане
askable(has_low_blood_pressure(_)). %ниско кръвно налягане
askable(are_you_under_12_years_old(_)). % под 12 години ли сте 
askable(has_you_taken_medicine_recently(_)). %пили ли сте скоро  лекарство
askable(has_you_sore_throat(_)). %болки в гърлото.
askable(has_muscle_pain(_)). % имате ли мускулни болки.
askable(has_joint_pain(_)). % имате ли ставни болки.
askable(has_stuffy_nose(_)). % зашушен ли ви е носа
askable(has_redness(_)). %зачервяване
askable(has_rash(_)). %задушаване
askable(has_watery_eyes(_)). % сълзене на очи
askable(has_menstrual_pain(_)).
