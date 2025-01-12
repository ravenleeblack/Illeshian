#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



int parse_type(enum scope_type current_scope)
{
    int data_type = 0;

    switch (Token.token_rep)
    {
        // Basic types
        case _num:        num(_num, "num");             data_type = type_num;    break;
        case _mark:       mark(_mark, "mark");          data_type = type_mark;   break;
        case _deci:       deci(_deci, "deci");          data_type = type_deci;   break;
        case _decii:      decii(_decii, "decii");       data_type = type_decii;  break;
   
        // System types
        case _den:        den(_den, "den");             data_type = type_den;    break;
        case _dens:       dens(_dens, "dens");          data_type = type_dens;   break;
        case _bay:        bay(_bay, "bay");             data_type = type_bay;    break;
        case _bays:       bays(_bays, "bays");          data_type = type_bays;   break;
        case _aisle:      aisle(_aisle, "aisle");       data_type = type_aisle;  break;
        case _aisles:     aisles(_aisles, "aisles");    data_type = type_aisle;  break;
        case _zone:       zone(_zone, "zone");          data_type = type_zone;   break;
        case _zones:      zones(_zones, "zones");       data_type = type_zones;  break;

        default: break;
    }

    return data_type;
}


int get_byte_size(int declare_type)
{
    switch(declare_type)
    {
        case type_num:     return 4;
        case type_mark:    return 1;
        case type_deci:    return 4;
        case type_decii:   return 8;
   
        // System types
        case type_den:     return 1; 
        case type_dens:    return 1; 
        case type_bay:     return 2;  
        case type_bays:    return 2;  
        case type_aisle:   return 4;  
        case type_aisles:  return 4;  
        case type_zone:    return 8; 
        case type_zones:   return 8;  
        default:           break;
    }
   return declare_type;
}


phrase_retrievel parse_pointer(enum scope_type current_scope)
{
    phrase_retrievel result;
    result.type = phrase_pointer; // Set the operand type

    switch(Token.token_rep)
    {
        case _num_ptr:    num_ptr(_num_ptr, "num_ptr");          break;
        case _mark_ptr:   mark_ptr(_mark_ptr, "mark_ptr");       break;
        case _deci_ptr:   deci_ptr(_deci_ptr, "deci_ptr");       break;
        case _decii_ptr:  decii_ptr(_decii_ptr, "decii_ptr");    break;

        case _den_ptr:    den_ptr(_den_ptr, "den_ptr");          break;
        case _bay_ptr:    bay_ptr(_bay_ptr, "bay_ptr");          break;
        case _aisle_ptr:  aisle_ptr(_aisle_ptr, "aisle_ptr");    break;
        case _zone_ptr:   zone_ptr(_zone_ptr, "zone_ptr");       break;
      
        case _dens_ptr:   dens_ptr(_dens_ptr, "dens_ptr");       break;
        case _bays_ptr:   bays_ptr(_bays_ptr, "bays_ptr");       break;
        case _aisles_ptr: aisles_ptr(_aisles_ptr, "aisles_ptr"); break;
        case _zones_ptr:  zones_ptr(_zones_ptr, "zones_ptr");    break;
    }

    scan(&Token);
    lbrace(_lbrace, "[");

    scan(&Token);
    ident(_ident, Text);
    strcpy(ptr_buffer, Text);
    result.phrase = ptr_buffer;

    switch (current_scope)
    {
        case scope_universal:    search_universal_scope(Text);    break;
        case scope_global:       search_global_scope(Text);       break;
        case scope_global_block: search_global_block_scope(Text); break;
        case scope_local:        search_local_scope(Text);        break;
        case scope_local_block:  search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    scan(&Token);
    rbrace(_rbrace, "]");

    return result;  // Return the populated pointer phrase
}

phrase_retrievel parse_address(enum scope_type current_scope)
{
    phrase_retrievel result;
    result.type = phrase_address; // Set the operand type

    address(_address, "address");

    scan(&Token);
    lbrace(_lbrace, "[");

    scan(&Token);
    ident(_ident, Text);
    strcpy(address_buffer, Text);
    result.phrase = address_buffer;

    switch (current_scope)
    {
        case scope_universal:    search_universal_scope(Text);    break;
        case scope_global:       search_global_scope(Text);       break;
        case scope_global_block: search_global_block_scope(Text); break;
        case scope_local:        search_local_scope(Text);        break;
        case scope_local_block:  search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    scan(&Token);
    rbrace(_rbrace, "]");

    return result;  // Return the populated address phrase
}

phrase_retrievel parse_fetch(enum scope_type current_scope)
{
    phrase_retrievel result;
    result.type = phrase_fetch; // Set the operand type

    fetch(_fetch, "fetch");

    scan(&Token);
    lbrace(_lbrace, "[");

    scan(&Token);
    ident(_ident, Text);
    strcpy(fetch_buffer, Text);
    result.phrase = fetch_buffer;

    switch (current_scope)
    {
        case scope_universal:    search_universal_scope(Text);    break;
        case scope_global:       search_global_scope(Text);       break;
        case scope_global_block: search_global_block_scope(Text); break;
        case scope_local:        search_local_scope(Text);        break;
        case scope_local_block:  search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    scan(&Token);
    rbrace(_rbrace, "]");

    return result;  // Return the populated fetch phrase
}
