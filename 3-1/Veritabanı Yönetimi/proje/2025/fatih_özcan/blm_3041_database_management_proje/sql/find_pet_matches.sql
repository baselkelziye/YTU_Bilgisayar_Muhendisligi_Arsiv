CREATE OR REPLACE FUNCTION find_pet_matches(input_pet_id INT)
RETURNS TABLE(
    pet_name TEXT, 
    species TEXT, 
    breed TEXT, 
    age INT, 
    weight NUMERIC, 
    owner_name TEXT
) AS $$
DECLARE
    pet_species TEXT;
    pet_breed TEXT;
    pet_age INT;
    pet_weight NUMERIC;
BEGIN
    -- Seçilen hayvanın özelliklerini al
    SELECT pets.species, pets.breed, pets.age, pets.weight 
    INTO pet_species, pet_breed, pet_age, pet_weight
    FROM pets
    WHERE pets.pet_id = input_pet_id;

    -- Eşleşmeleri sorgula
    RETURN QUERY
    SELECT 
        p.name::TEXT, -- Tür dönüşümü yapıldı
        p.species::TEXT,
        p.breed::TEXT,
        p.age,
        p.weight,
        u.username::TEXT -- Tür dönüşümü yapıldı
    FROM pets p
    JOIN users u ON p.user_id = u.user_id
    WHERE 
        p.pet_id != input_pet_id
        AND p.species = pet_species;
END;
$$ LANGUAGE plpgsql;
