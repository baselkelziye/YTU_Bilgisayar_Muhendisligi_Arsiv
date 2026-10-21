CREATE OR REPLACE FUNCTION calculate_human_age(pet_age INT, pet_species TEXT)
RETURNS INT AS $$
BEGIN
    CASE
        WHEN pet_species = 'Köpek' THEN RETURN pet_age * 7;
        WHEN pet_species = 'Kedi' THEN RETURN pet_age * 6;
        ELSE RETURN pet_age * 5;
    END CASE;
END;
$$ LANGUAGE plpgsql;
