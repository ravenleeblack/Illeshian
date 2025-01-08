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
        case _mark:       mark(_mark, "mark");          data_type = type_mark;       is_ptr = 0; break;
        case _num:        num(_num, "num");             data_type = type_num;        is_ptr = 0; break;
        case _deci:       deci(_deci, "deci");          data_type = type_deci;       is_ptr = 0; break;
        case _decii:      decii(_decii, "decii");       data_type = type_decii;      is_ptr = 0; break;
        case _strand:     strand(_strand, "strand");    data_type = type_strand;     is_ptr = 0; break;
        
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

        default:  data_type = 0;  tool_type =0;  is_ptr = 0; break;
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


struct phrase *parse_pointer(enum scope_type current_scope)
{
    struct phrase *pointer_op = malloc(sizeof(struct phrase));  // Allocate memory for the phrase struct
    
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

    // Store the identifier with brackets in strand_op
    pointer_op->strand_op = malloc(strlen(Text) + 3);  // +3 for the brackets
    snprintf(pointer_op->strand_op, strlen(Text) + 3, "[%s]", Text);  // Add brackets around identifier

    switch (current_scope)
    {
        case scope_universal:    pointer_op->ident_op = search_universal_scope(Text);    break;
        case scope_global:       pointer_op->ident_op = search_global_scope(Text);       break;
        case scope_global_block: pointer_op->ident_op = search_global_block_scope(Text); break;
        case scope_local:        pointer_op->ident_op = search_local_scope(Text);        break;
        case scope_local_block:  pointer_op->ident_op = search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    scan(&Token);
    rbrace(_rbrace, "]");

    return pointer_op;  // Return the populated pointer phrase
}

struct phrase *parse_address(enum scope_type current_scope)
{
    struct phrase *address_op = malloc(sizeof(struct phrase));  // Allocate memory for the phrase struct
    address(_address, "address");

    scan(&Token);
    lbrace(_lbrace, "[");

    scan(&Token);
    ident(_ident, Text);

    // Store the identifier with brackets in strand_op
    address_op->strand_op = malloc(strlen(Text) + 3);  // +3 for the brackets
    snprintf(address_op->strand_op, strlen(Text) + 3, "[%s]", Text);  // Add brackets around identifier

    switch (current_scope)
    {
        case scope_universal:    address_op->ident_op = search_universal_scope(Text);    break;
        case scope_global:       address_op->ident_op = search_global_scope(Text);       break;
        case scope_global_block: address_op->ident_op = search_global_block_scope(Text); break;
        case scope_local:        address_op->ident_op = search_local_scope(Text);        break;
        case scope_local_block:  address_op->ident_op = search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    scan(&Token);
    rbrace(_rbrace, "]");

    return address_op;  // Return the populated address phrase
}

struct phrase *parse_fetch(enum scope_type current_scope)
{
    struct phrase *fetch_op = malloc(sizeof(struct phrase));  // Allocate memory for the phrase struct

    fetch(_fetch, "fetch");

    scan(&Token);
    lbrace(_lbrace, "[");

    scan(&Token);
    ident(_ident, Text);

    // Store the identifier with brackets in strand_op
    fetch_op->strand_op = malloc(strlen(Text) + 3);  // +3 for the brackets
    snprintf(fetch_op->strand_op, strlen(Text) + 3, "[%s]", Text);  // Add brackets around identifier

    switch (current_scope)
    {
        case scope_universal:    fetch_op->ident_op = search_universal_scope(Text);    break;
        case scope_global:       fetch_op->ident_op = search_global_scope(Text);       break;
        case scope_global_block: fetch_op->ident_op = search_global_block_scope(Text); break;
        case scope_local:        fetch_op->ident_op = search_local_scope(Text);        break;
        case scope_local_block:  fetch_op->ident_op = search_local_block_scope(Text);  break;
        default: error("ident error: invalid ident token"); break;
    }

    scan(&Token);
    rbrace(_rbrace, "]");

    return fetch_op;  // Return the populated fetch phrase
}