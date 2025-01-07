#include "seed_defs.h"
#include "seed_data.h"
#include "seed_decl.h"



int parse_type(enum scope_type current_scope)
{
    int data_type = 0;
    int tool_type = 0;

    int is_ptr = 0;

    switch (Token.token_rep)
    {
        // Basic types
        case _mark:       mark(_mark, "mark");           data_type = type_mark;       is_ptr = 0; break;
        case _num:        num(_num, "num");             data_type = type_num;        is_ptr = 0; break;
        case _deci:       deci(_deci, "deci");          data_type = type_deci;       is_ptr = 0; break;
        case _decii:      decii(_decii, "decii");       data_type = type_decii;      is_ptr = 0; break;
        case _strand:     strand(_strand, "strand");     data_type = type_strand;     is_ptr = 0; break;
        
        // System types
        case _zone:       zone(_zone, "zone");          data_type = type_zone;       is_ptr = 0; break;
        case _zones:      zones(_zones, "zones");       data_type = type_zones;      is_ptr = 0; break;
        case _aisle:      aisle(_aisle, "aisle");       data_type = type_aisle;      is_ptr = 0; break;
        case _aisles:     aisles(_aisles, "aisles");    data_type = type_aisles;     is_ptr = 0; break;
        case _bay:        bay(_bay, "bay");             data_type = type_bay;        is_ptr = 0; break;
        case _bays:       bays(_bays, "bays");          data_type = type_bays;       is_ptr = 0; break;
        case _den:        den(_den, "den");             data_type = type_den;        is_ptr = 0; break;
        case _dens:       dens(_dens, "dens");          data_type = type_dens;       is_ptr = 0; break;
        
        // Container types
        case _log:        match_log(_log, "log");       data_type = type_log;        is_ptr = 0; break;

        // Pointer types
        case _num_ptr:    num_ptr(_num_ptr, "num_ptr");          data_type = type_num_ptr;     tool_type = tool_mark_ptr;   is_ptr = 1;  break;
        case _mark_ptr:   mark_ptr(_mark_ptr, "mark_ptr");       data_type = type_mark_ptr;    tool_type = tool_mark_ptr;   is_ptr = 1;  break;
        case _deci_ptr:   deci_ptr(_deci_ptr, "deci_ptr");       data_type = type_deci_ptr;    tool_type = tool_deci_ptr;   is_ptr = 1;  break;
        case _decii_ptr:  decii_ptr(_decii_ptr, "decii_ptr");    data_type = type_decii_ptr;   tool_type = tool_decii_ptr;  is_ptr = 1;  break;

        case _den_ptr:    den_ptr(_den_ptr, "den_ptr");          data_type = type_den_ptr;     tool_type = tool_den_ptr;    is_ptr = 1;  break;
        case _bay_ptr:    bay_ptr(_bay_ptr, "bay_ptr");          data_type = type_bay_ptr;     tool_type = tool_bay_ptr;    is_ptr = 1;  break;
        case _aisle_ptr:  aisle_ptr(_aisle_ptr, "aisle_ptr");    data_type = type_aisle_ptr;   tool_type = tool_aisle_ptr;  is_ptr = 1;  break;
        case _zone_ptr:   zone_ptr(_zone_ptr, "zone_ptr");       data_type = type_zone_ptr;    tool_type = tool_zone_ptr;   is_ptr = 1;  break;
      
        case _dens_ptr:   dens_ptr(_dens_ptr, "dens_ptr");       data_type = type_dens_ptr;    tool_type = tool_dens_ptr;   is_ptr = 1;  break;
        case _bays_ptr:   bays_ptr(_bays_ptr, "bays_ptr");       data_type = type_bays_ptr;    tool_type = tool_bays_ptr;   is_ptr = 1;  break;
        case _aisles_ptr: aisles_ptr(_aisles_ptr, "aisles_ptr"); data_type = type_aisles_ptr;  tool_type = tool_aisles_ptr; is_ptr = 1;  break;
        case _zones_ptr:  zones_ptr(_zones_ptr, "zones_ptr");    data_type = type_zones_ptr;   tool_type = tool_zones_ptr;  is_ptr = 1;  break;
        default:  data_type = 0;  tool_type =0;  is_ptr = 0; break;
    }

    if (is_ptr == 1)
    {
        //nasm_state.is_pointer = true;
        scan(&Token);
        lbrace(_lbrace, "[");

        scan(&Token);
        ident(_ident, Text);
        
        switch(current_scope) {
            case scope_universal:     insert_universal_scope(Text, tool_type, data_type);     break;  
            case scope_global:        insert_global_scope(Text, tool_type, data_type);        break;
            case scope_global_param:  insert_global_param_scope(Text, tool_type, data_type);  break;
            case scope_global_block:  insert_global_block_scope(Text, tool_type, data_type);  break;
            case scope_local:         insert_local_scope(Text, tool_type, data_type);         break;
            case scope_local_param:   insert_local_param_scope(Text, tool_type, data_type);   break; 
            case scope_local_block:   insert_local_block_scope(Text, tool_type, data_type);   break;
            default:  error("seeding error: declare error: Invalid scope for declaration"); break;
        }

        scan(&Token);
        rbrace(_rbrace, "]"); 
    }
    else {
        //nasm_state.is_pointer = false;
    }
    return data_type;
}


int get_byte_size(int declare_type)
 {
    switch(declare_type) {
        case type_num:    return 4;
        case type_bay:    return 2;
        case type_mark:   return 1;
        case type_zone:   return 8;
        default:          return 0;  // Handle invalid types
    }

}

int parse_address(enum scope_type current_scope)
{
    char* current_placeholder;

    address(_address, "address");

    scan(&Token);
    lbrace(_lbrace, "[");

    scan(&Token);
    current_placeholder = parse_ident(current_scope);

    scan(&Token);
    rbrace(_rbrace, "]");

    return current_placeholder; // Return the fetched scope index
}

int parse_fetch(enum scope_type current_scope)
{
    char* current_placeholder;

    int current_index = 0;

    fetch(_fetch, "fetch");

    scan(&Token);
    lbrace(_lbrace, "[");

    scan(&Token);
    current_placeholder = parse_ident(current_scope);

    scan(&Token);
    rbrace(_rbrace, "]");

    return current_placeholder; // Return the fetched scope index
}