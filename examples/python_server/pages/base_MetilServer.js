var key_down_beg_repeat = 300;
var key_down_con_repeat =  30;
var timer_key_down = null;
var python_commands = "";

function my_xml_http_request() {
    if( window.XMLHttpRequest ) // Firefox
        return new XMLHttpRequest();
    if ( window.ActiveXObject ) // Internet Explorer
        return new ActiveXObject("Microsoft.XMLHTTP");
    alert("Votre navigateur ne supporte pas les objets XMLHTTPRequest...");
}

function send_async_xml_http_request( url, data, func ) {
    var xhr_object = my_xml_http_request();
    xhr_object.open( "POST", url, true );
    xhr_object.onreadystatechange = function() {
        if( this.readyState == 4 && this.status == 200 )
            func( this.responseText );
    };
    xhr_object.send( data );
}

function queue_python_cmd( cmd ) {
    python_commands += cmd + "\n";
}

function exec_python_cmds() {
    send_async_xml_http_request( "exec.py", python_commands, function( rep ) {
        c = {};
        alert( rep );
        eval( rep );
        if ( c.err && c.err.length )
            alert( c.err );
    } );
    python_commands = "";
}

function get_login() {
    return "<b>login@sc:$</b> ";
}

function code_to_html( code ) {
    return code.replace( / /gi, "&nbsp;" ).replace( /\n/gi, "<br/>" );
}

function update_text( doc ) {
    txt = "<tt>";
    for( var i in doc.lines ) {
        var item = doc.lines[ i ];
        if ( i != 0 )
            txt += "<br/>";
        txt += item.prompt

        txt += code_to_html( item.cmd.slice( 0, item.cursor ) );
        txt += '<u>'; //  class="cursor"
        txt += code_to_html( item.cursor < item.cmd.length ? item.cmd.charAt( item.cursor ) : " " );
        txt += '</u>';
        txt += code_to_html( item.cmd.slice( item.cursor + 1 ) );

        if ( item.out )
            txt += "<br/>" + code_to_html( item.out );
        if ( item.err )
            txt += "<br/>" + code_to_html( item.err );
    }
    txt += "</tt>";

    //
    doc.open();
    doc.write( txt );
    doc.close();

    doc.frame.contentWindow.scrollTo( 0, doc.height );
}

function new_line() {
    return { cmd : "", cursor : 0, prompt : get_login() };
}

function key_up( evt ) {
    if ( timer_key_down != null ) {
        clearTimeout( timer_key_down );
        timer_key_down = null;
    }
}

function dialog_key_down( evt ) {
    var event = evt || window.event;
    var doc = this;
    
    var caught  = false;
    var end_dialog = false;
    switch ( event.keyCode ) {
        case 38: // up
            if ( doc.selected_line > 0 ) {
                doc.dialog.childNodes[ doc.selected_line ].setAttribute( 'class', '' );
                doc.selected_line -= 1;
                doc.dialog.childNodes[ doc.selected_line ].setAttribute( 'class', 'selected_line' );
            }
            caught = true;
            break;
        case 40: // down
            if ( doc.selected_line < doc.dialog.childNodes.length - 1 ) {
                doc.dialog.childNodes[ doc.selected_line ].setAttribute( 'class', '' );
                doc.selected_line += 1;
                doc.dialog.childNodes[ doc.selected_line ].setAttribute( 'class', 'selected_line' );
            }
            caught = true;
            break;
        case 13: // CR
            if ( doc.lines.length > 0 ) {
                current_line = doc.lines[ doc.lines.length - 1 ];
                current_line.cmd = doc.lst_cmd[ doc.selected_line ];
                current_line.cursor = current_line.cmd.length;
                update_text( doc );
            }
        case 27: // ESC
            end_dialog = true;
            break;
        case 8 : // backspace
            doc.lst_cmd_filter = doc.lst_cmd_filter.slice( 0, doc.lst_cmd_filter.length - 1 );
            update_lst_cmd( doc );
            caught = true;
            break;
        default:
    }

    // end dialog
    if ( end_dialog ) {
        doc.overlay.style.display = "none";
        doc.dialog. style.display = "none";
        doc.onkeydown  = key_down;
        doc.onkeypress = null;
        event.preventDefault();
        return false;
    }
    
    //
    if ( caught ) {
        doc.onkeydown  = dialog_key_down;
        doc.onkeypress = null;
        doc.onkeyup    = key_up;
        event.preventDefault();
        
        dur = timer_key_down != null ? key_down_con_repeat : key_down_beg_repeat;
        timer_key_down = setTimeout( function() {
            if ( timer_key_down != null )
                doc.onkeydown( evt );
        }, dur );
        return false;
    }

    doc.onkeydown  = dialog_key_down;
    doc.onkeypress = dialog_key_press;
    event.preventDefault();
    return true; // because we want keypress
    
}

function update_dialog_lst( doc ) {
    // delete old children
    dialog = doc.dialog;
    if ( dialog.hasChildNodes() )
        while ( dialog.childNodes.length >= 1 )
            dialog.removeChild( dialog.firstChild );
    // make elements
    for( var i = doc.lst_cmd.length - 1; i >= 0; i -= 1 ) {
        div = doc.dialog.appendChild( document.createElement( 'div' ) );
        div.appendChild( document.createTextNode( "> " + doc.lst_cmd[ i ] ) );
        dialog.appendChild( div );
    }
    // selected_line
    if ( doc.selected_line >= doc.lst_cmd.length )
        doc.selected_line = doc.lst_cmd.length - 1;
    if ( doc.selected_line >= 0 )
        dialog.childNodes[ doc.selected_line ].setAttribute( 'class', 'selected_line' );
    
    // filter
    div = doc.dialog.appendChild( document.createElement( 'div' ) );
    div.appendChild( document.createTextNode( "filter: " + doc.lst_cmd_filter ) );
    div.setAttribute( 'class', 'dialog_filter' );
    dialog.appendChild( div );
}

function update_lst_cmd( doc ) {
    // lst_cmd from lst_cmd_full
    doc.lst_cmd = [];
    for( var i in doc.lst_cmd_full )
        if ( doc.lst_cmd_full[ i ].indexOf( doc.lst_cmd_filter ) >= 0 )
            doc.lst_cmd.push( doc.lst_cmd_full[ i ] );

    // update display
    update_dialog_lst( doc );
}

function dialog_key_press( evt ) {
    var event = evt || window.event;
    var doc = this;
    
    doc.lst_cmd_filter += String.fromCharCode( event.which || event.charCode );
    update_lst_cmd( doc );

    this.onkeydown  = dialog_key_down ;
    this.onkeypress = dialog_key_press;
    event.preventDefault();
    return false;
}

function list_has_not( lst, key ) {
    for( var i = 0; i < lst.length; i += 1 )
        if ( lst[ i ] == key )
            return false;
    return true;
}

function show_history( doc ) {
    if ( doc.dialog == null ) {
        doc.overlay = document.createElement( 'div' ); doc.overlay.setAttribute( 'class', 'overlay' );
        doc.dialog  = document.createElement( 'div' ); doc.dialog .setAttribute( 'class', 'dialog'  );
        document.body.appendChild( doc.overlay ); 
        document.body.appendChild( doc.dialog  ); 
    } else {
        doc.overlay.style.display = "block";
        doc.dialog. style.display = "block";
    }

    // content
    var lst = [];
    for( var i = doc.lines.length - 1; i >= 0; i -= 1 )
        if ( doc.lines[ i ].cmd.length >= 1 && list_has_not( lst, doc.lines[ i ].cmd ) )
            lst.push( doc.lines[ i ].cmd );
    doc.lst_cmd = lst.reverse();
    doc.lst_cmd_full = doc.lst_cmd;
    doc.lst_cmd_filter = '';
    doc.selected_line = doc.lst_cmd.length - 1;
    
    //
    update_dialog_lst( doc );
    
    doc.onkeydown  = dialog_key_down;
    doc.onkeypress = null;
}

function key_down( evt ) {
    var event = evt || window.event;
    var repaint = false;
    var caught  = false;
    var doc = this;
    var current_line = doc.lines[ doc.lines.length - 1 ];

    // cur to previous word
    function l_cur( cmd, cursor ) {
        if ( cursor )
            cursor -= 1;
        // skip the spaces
        while ( cursor > 0 && cmd[ cursor ] == " " )
            cursor -= 1;
        // skip the word
        while ( cursor > 0 && cmd[ cursor - 1 ] != " " )
            cursor -= 1;
        return cursor;
    }
    
    // cur to next word
    function r_cur( cmd, cursor ) {
        // skip the word
        while ( cursor < cmd.length && cmd[ cursor ] != " " )
            cursor += 1;
        // skip the spaces
        while ( cursor < cmd.length && cmd[ cursor ] == " " )
            cursor += 1;
        return cursor;
    }

    // current_line.cmd += event.keyCode;
    switch ( event.keyCode ) {
        case 13: // CR
            // new prompt
            doc.lines.push( new_line() );

            // send a request -> repaint
//             send_async_xml_http_request( "exec.py", current_line.cmd, function( rep ) {
//                 var c = current_line;
//                 eval( rep );
//                 update_text( doc );
//                 doc.onkeydown  = key_down;
//                 doc.onkeypress = null;
//             } );
            update_text( doc );
        case 0 : // ?
        case 16: // shift
        case 17: // ctrl
        case 18: // meta
            doc.onkeydown  = key_down;
            doc.onkeypress = null;
            event.preventDefault();
            return false;

        case 9 : // tab
        case 20: // caps-lock
        case 27: // esc
            caught = true;
            break;
        case 8 : // backspace
            if ( event.ctrlKey ) {
                var old_cursor = current_line.cursor;
                current_line.cursor = l_cur( current_line.cmd, current_line.cursor );
                current_line.cmd = current_line.cmd.slice( 0, current_line.cursor ) + current_line.cmd.slice( old_cursor );
            } else {
                current_line.cmd = current_line.cmd.slice( 0, current_line.cursor - 1 ) + current_line.cmd.slice( current_line.cursor );
                current_line.cursor = Math.max( current_line.cursor - 1, 0 );
            }
            repaint = true;
            break;
        case 46: // suppr
            if ( event.ctrlKey ) {
                var new_cursor = r_cur( current_line.cmd, current_line.cursor );
                current_line.cmd = current_line.cmd.slice( 0, current_line.cursor ) + current_line.cmd.slice( new_cursor );
            } else
                current_line.cmd = current_line.cmd.slice( 0, current_line.cursor ) + current_line.cmd.slice( current_line.cursor + 1 );
            repaint = true;
            break;
        case 36: // beg line
            current_line.cursor = 0;
            repaint = true;
            break;
        case 35: // end line
            current_line.cursor = current_line.cmd.length;
            repaint = true;
            break;
        case 38: // up
            show_history( doc );
            return true;
        case 40: // down
            current_line.cursor = Math.max( 0, current_line.cursor - 1 );
            repaint = true;
            break;
        case 37: // left
            if ( event.ctrlKey )
                current_line.cursor = l_cur( current_line.cmd, current_line.cursor );
            else
                current_line.cursor = Math.max( 0, current_line.cursor - 1 );
            repaint = true;
            break;
        case 39: // right
            if ( event.ctrlKey )
                current_line.cursor = r_cur( current_line.cmd, current_line.cursor );
            else
                current_line.cursor = Math.min( current_line.cmd.length, current_line.cursor + 1 );
            repaint = true;
            break;
        case 86: // V
            if ( event.ctrlKey ) {
                txt = window.clipboardData.getData( "Text" );
                current_line.cmd += txt;
                current_line.cursor += txt.length;
                repaint = true;
            }
            break;
    }

    //
    if ( repaint )
        update_text( this );

    //
    if ( caught || repaint ) {
        this.onkeydown  = key_down;
        this.onkeypress = null;
        this.onkeyup    = key_up;
        event.preventDefault();
        
        dur = timer_key_down != null ? key_down_con_repeat : key_down_beg_repeat;
        timer_key_down = setTimeout( function() {
            if ( timer_key_down != null )
                doc.onkeydown( evt );
        }, dur );
        return false;
    }

    this.onkeydown  = key_down ;
    this.onkeypress = key_press;
    return true; // because we want keypress
}

function key_press( evt ) {
    var event = evt || window.event;
    var current_line = this.lines[ this.lines.length - 1 ];

    var old_cmd = current_line.cmd;
    current_line.cmd = old_cmd.slice( 0, current_line.cursor );
    current_line.cmd += String.fromCharCode( event.which || event.charCode ); //
    current_line.cmd += old_cmd.slice( current_line.cursor, old_cmd.length );
    current_line.cursor += 1;
    // current_line.cmd += event.keyCode;

    update_text( this );

    this.onkeydown  = key_down ;
    this.onkeypress = key_press;
    event.preventDefault();
    return false;
}

function init_frame_as_terminal( name ) {
    var my_frame = document.getElementById( name );
    var doc = my_frame.contentDocument;
    if ( ! doc )
        doc = my_frame.contentWindow.document;
    doc.frame = my_frame;
    doc.lines = [ new_line() ];
    update_text( doc );

    doc.onkeydown  = key_down;
    my_frame.style.visibility = "visible";
}




// function DialogOverlay( content, container ) {
//     // Manage arguments and assign defaults,
//     //     if ( typeof container == 'undefined' ) container = document.body;
//     //     if ( null == (this.container = $(container)) ) throw("container is not valid");
//  
//     // Assign instance variables
//     this.content = content;
//     this.overlay = new Element( 'div', { 'class': 'overlay' } ).hide();
//     this.dialog = new Element( 'div', { 'class': 'dialog' } ).hide();
//  
//     // Hide the overlay when clicked. Ignore clicks on the dialog.
//     Event.observe( this.overlay, 'click', this.hide.bindAsEventListener(this) );
//     Event.observe( this.dialog, 'click',  function( event ) { Event.stop( event ) } );
//  
//     // Insert the elements into the DOM
//     this.dialog.insert( this.content );
//     this.container.insert( this.overlay );
//     this.container.insert( this.dialog );
//  
//     // Content may have been hidden if it is embedded in the page
//     content.show();
//     this.dialog.hide();
// }
// DialogOverlay.prototype.show = function() {
//     new Effect.Appear( this.overlay, { duration: 0.5,  to: 0.8 } );
//     this.dialog.show();
//     return this;
// };
// DialogOverlay.prototype.hide = function(event) {
//     this.dialog.hide();
//     this.overlay.hide();
//     return this;
// };
