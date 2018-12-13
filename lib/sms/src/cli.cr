# vim: et ts=2 sw=2

module Cli
  def add_header(args)
    comp, incl = args.split("=", 2)
    pathstr, typestr = comp.split(".", 2)

    path = pathstr.split("::")
    mod = path[0..-2]
    comp = path.last

    incl_type =
      if incl.starts_with?("./")
        nil
      else
        :system
      end

    scope =
      case typestr
      when "h"
        :public
      when "cpp"
        :private
      else
        raise ArgumentError.new("Unknown file type #{typestr}")
      end

    if incl_type
      conf_add_comp_includes(incl, mod, comp, incl_type, scope)
    else
      conf_add_comp_includes(incl, mod, comp, scope)
    end
  end
end
