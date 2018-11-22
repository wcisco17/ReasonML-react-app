



/* https://reasonml.chat/t/cant-apply-interface-because-it-is-unbound/357/2 */



/* Define State */


type state = {
    /* items: list(TodoType.todo), */
    inputText: string,
};

type action =
  | InputText(string)
  | Toggle(int)
  | RemoveItem(int)
  | Submit;


  let component = ReasonReact.statelessComponent("App");


let make = (_children) => {
        /* let handleSubmit = state => {
            let newId: int = List.length(state.items);
        }; */
    {
        ...component,
            render: _self => {
                let title = <h2 className="header" >(ReasonReact.string("Reason Todo"))</h2>;
                <div className="container" >
                (title)
                <input className="search__input" placeholder="Add Todo"
                onChange=(e => Js.log(e) )
                />
                </div>;
            },
        }
    }