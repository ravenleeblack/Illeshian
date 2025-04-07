#include "comp_def.h"  
#include "comp_data.h"   
#include "comp_decl.h" 




int parse_type(void)
{
    int type = 0;
    int is_ptr = 0;

    // First switch - non-pointer types
    switch (Token.token_rep)
    {
        // Basic types
        case _mark:       mark(_mark, "mark");           type = type_mark;       is_ptr = 0; break;
        case _num:        num(_num, "num");             type = type_num;        is_ptr = 0; break;
        case _hollow:     hollow(_hollow, "hollow");     type = type_hollow;     is_ptr = 0; break;
        case _deci:       deci(_deci, "deci");          type = type_deci;       is_ptr = 0; break;
        case _decii:      decii(_decii, "decii");       type = type_decii;      is_ptr = 0; break;
        case _strand:     strand(_strand, "strand");     type = type_strand;     is_ptr = 0; break;
        
        // System types
        case _zone:       zone(_zone, "zone");          type = type_zone;       is_ptr = 0; break;
        case _zones:      zones(_zones, "zones");       type = type_zones;      is_ptr = 0; break;
        case _aisle:      aisle(_aisle, "aisle");       type = type_aisle;      is_ptr = 0; break;
        case _aisles:     aisles(_aisles, "aisles");    type = type_aisles;     is_ptr = 0; break;
        case _bay:        bay(_bay, "bay");             type = type_bay;        is_ptr = 0; break;
        case _bays:       bays(_bays, "bays");          type = type_bays;       is_ptr = 0; break;
        case _den:        den(_den, "den");             type = type_den;        is_ptr = 0; break;
        case _dens:       dens(_dens, "dens");          type = type_dens;       is_ptr = 0; break;
        
        // Container types
        case _log:        match_log(_log, "log");       type = type_log;        is_ptr = 0; break;
        case _list:       list(_list, "list");          type = type_list;       is_ptr = 0; break;
        case _table:      table(_table, "table");       type = type_table;      is_ptr = 0; break;

        // Special types
        case _proto:      proto(_proto, "proto");       type = type_prototype;   is_ptr = 0; break;
        case _pare:       pare(_pare, "pare");          type = type_pare;        is_ptr = 0; break;
        case _tripare:    tripare(_tripare, "tripare"); type = type_tripare;     is_ptr = 0; break;
        case _vine:       vine(_vine, "vine");          type = type_vine;        is_ptr = 0; break;
        case _passage:    passage(_passage, "passage"); type = type_passage;     is_ptr = 0; break;


        case _mark_ptr:   mark_ptr(_mark_ptr, "mark_ptr");       type = type_mark_ptr;    is_ptr = 1; break;
        case _num_ptr:    num_ptr(_num_ptr, "num_ptr");          type = type_num_ptr;     is_ptr = 1; break;
        case _hollow_ptr: hollow_ptr(_hollow_ptr, "hollow_ptr"); type = type_hollow_ptr;  is_ptr = 1; break;
        case _deci_ptr:   deci_ptr(_deci_ptr, "deci_ptr");       type = type_deci_ptr;    is_ptr = 1; break;
        case _zone_ptr:   zone_ptr(_zone_ptr, "zone_ptr");       type = type_zone_ptr;    is_ptr = 1; break;
        case _aisle_ptr:  aisle_ptr(_aisle_ptr, "aisle_ptr");    type = type_aisle_ptr;   is_ptr = 1; break;
        case _bay_ptr:    bay_ptr(_bay_ptr, "bay_ptr");          type = type_bay_ptr;     is_ptr = 1; break;
        case _den_ptr:    den_ptr(_den_ptr, "den_ptr");          type = type_den_ptr;     is_ptr = 1; break;
        default: break;
    }

    // Only check for [] conversion if not already a pointer type
    if (is_ptr == 1)
    {
        set_express_state(express_ptr_arg);
        struct scope_table_entry* result = parse_expressions(); 
    }


    return type;
}


int get_address(void)
{
    int type;

    address(_address, "address");
    
    type = type_address;    
    
    // Match address[] operator
    if (Token.token_rep == _lbrace) 
    {        
        lbrace(_lbrace, "[");

        set_express_state(express_address);
        struct scope_table_entry* result = parse_expressions();
          
        scan(&Token);
        if (Token.token_rep == _rbrace) 
        {
            rbrace(_rbrace, "]");
        }
    }
    
    return type;  // Return the type instead of NULL
}


int fetch_value(void)
{
    int type;

    fetch(_fetch, "fetch");
    
    type = type_fetch;    

    // Match fetch[] operator for dereferencing
    if (Token.token_rep == _lbrace) 
    {        
        lbrace(_lbrace, "[");

        set_express_state(express_fetch);
        struct scope_table_entry* result = parse_expressions();
          
        scan(&Token);
        if (Token.token_rep == _rbrace) 
        {
            rbrace(_rbrace, "]");
        }
    }
    
    return type;  // Return the type instead of NULL
}


int convert_to_ptr(int prev_type)
{
    int convert_type;

    switch (prev_type)
    {
        // Basic types to pointers
        case type_hollow:  convert_type = type_hollow_ptr;  break;
        case type_mark:    convert_type = type_mark_ptr;    break;
        case type_num:     convert_type = type_num_ptr;     break;
        case type_long:    convert_type = type_long_ptr;    break;
        case type_deci:    convert_type = type_deci_ptr;    break;
        case type_decii:   convert_type = type_decii_ptr;   break;
        case type_strand:  convert_type = type_strand_ptr;  break;
        
        // Container types to pointers
        case type_log:     convert_type = type_log_ptr;     break;
        case type_list:    convert_type = type_list_ptr;    break;
        case type_table:   convert_type = type_table_ptr;   break;
        
        // System types to pointers
        case type_zone:    convert_type = type_zone_ptr;    break;
        case type_zones:   convert_type = type_zones_ptr;   break;
        case type_aisle:   convert_type = type_aisle_ptr;   break;
        case type_aisles:  convert_type = type_aisles_ptr;  break;
        case type_bay:     convert_type = type_bay_ptr;     break;
        case type_bays:    convert_type = type_bays_ptr;    break;
        case type_den:     convert_type = type_den_ptr;     break;
        case type_dens:    convert_type = type_dens_ptr;    break;

        default: break;
    }
    return (convert_type);
}


int convert_to_type(int prev_type)
{
    int convert_type;

    switch (prev_type)
    {
        // Basic pointer types back to types
        case type_hollow_ptr:  convert_type = type_hollow;  break;
        case type_mark_ptr:    convert_type = type_mark;    break;
        case type_num_ptr:     convert_type = type_num;     break;
        case type_long_ptr:    convert_type = type_long;    break;
        case type_deci_ptr:    convert_type = type_deci;    break;
        case type_decii_ptr:   convert_type = type_decii;   break;
        case type_strand_ptr:  convert_type = type_strand;  break;
        
        // Container pointer types back to types
        case type_log_ptr:     convert_type = type_log;     break;
        case type_list_ptr:    convert_type = type_list;    break;
        case type_table_ptr:   convert_type = type_table;   break;
        
        // System pointer types back to types
        case type_zone_ptr:    convert_type = type_zone;    break;
        case type_zones_ptr:   convert_type = type_zones;   break;
        case type_aisle_ptr:   convert_type = type_aisle;   break;
        case type_aisles_ptr:  convert_type = type_aisles;  break;
        case type_bay_ptr:     convert_type = type_bay;     break;
        case type_bays_ptr:    convert_type = type_bays;    break;
        case type_den_ptr:     convert_type = type_den;     break;
        case type_dens_ptr:    convert_type = type_dens;    break;

        default: break;
    }
    return (convert_type);
}




struct scope_table_entry* parse_ptr_arg(void)
{
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_ptr_arg)
    {
        scan(&Token);
        lbrace(_lbrace, "[");

        scan(&Token);
        if (Token.token_rep == _ident)
        {
            ident(_ident, Text); 
        }
        else
        {
            entry = parse_type();

            scan(&Token);
            if (Token.token_rep == _table)
            {
                table(_table, "table");

                scan(&Token);
                colon(_colon, ":");

                scan(&Token);
                ident(_ident, Text);

                scan(&Token);
                lbrace(_lbrace, "[");

                scan(&Token);
                rbrace(_rbrace, "]");
            }
        }

        scan(&Token);
        rbrace(_rbrace, "]");
    }
    return entry;
}

struct scope_table_entry* parse_address(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_address) {
        // Match tokens for address pattern
        // address[var]
    }
    return entry;
}

struct scope_table_entry* parse_fetch(void) {
    express_state_machine state = get_express_state();
    struct scope_table_entry* entry = NULL;
    
    if (state == express_fetch) {
        // Match tokens for deref pattern
        // *ptr
    }
    return entry;
}
